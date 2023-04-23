#include <cstdio>
#include <stdexcept>
#include <functional>


struct SpeedUpdate {
    double velocity_mps;
};

struct CarDetected {
    double distance_m;
    double velocity_mps;
};

struct BrakeCommand {
    double time_to_collision_s;
};

using SpeedUpdateCallback = std::function<void(const SpeedUpdate&)>;
using CarDetectedCallback = std::function<void(const CarDetected&)>;

struct IServiceBus {
    virtual ~IServiceBus() = default;
    virtual void publish(const BrakeCommand&) = 0;
    virtual void subscribe(SpeedUpdateCallback) = 0;
    virtual void subscribe(CarDetectedCallback) = 0;
};

struct MockServiceBus : IServiceBus {
    void publish(const BrakeCommand& cmd) override {
        commands_published++;
        last_command = cmd;
    }
    void subscribe(SpeedUpdateCallback callback) override {
        speed_update_callback = callback;
    }
    void subscribe(CarDetectedCallback callback) override {
        car_detected_callback = callback;
    }
    BrakeCommand last_command{};
    int commands_published{};
    SpeedUpdateCallback speed_update_callback{};
    CarDetectedCallback car_detected_callback{};
};
//template <typename T>
struct AutoBrake {
    AutoBrake(IServiceBus& bus) : speed_mps {}, collision_threshold_s {5} {}
    void observe(const SpeedUpdate&) {}
    void observe(const CarDetected&) {}
    void set_collision_threshold_s(double x) {
        std::string errorMessage = std::string("Collision threshold less than 1.");
        if (x < 1) throw std::logic_error { "Collision threshold less than 1." };
        collision_threshold_s = x;
    }
    double get_collision_threshold_s() const { return collision_threshold_s; }
    double get_speed_mps() const { return speed_mps; }
private:
    double collision_threshold_s;
    double speed_mps;
};

constexpr void assert_that(bool statement, const char* message) {
    if (!statement) throw std::runtime_error{message};
}

void initial_speed_is_zero() {
    MockServiceBus bus{};
    AutoBrake auto_brake { bus };
    assert_that(auto_brake.get_speed_mps() == 0L, "speed not equal 0");
}

void initial_sensitivity_is_five() {
    MockServiceBus bus{};
    AutoBrake auto_brake { bus };
    assert_that(auto_brake.get_collision_threshold_s() == 5L, "sensitivity is not equal 5");
}

void sensitivity_greater_than_1() {
    MockServiceBus bus{};
    AutoBrake auto_brake {bus};
    try {
        auto_brake.set_collision_threshold_s(0.5L);
    } catch (const std::exception&) {
        return;
    }
    assert_that(false, "no exception thrown");
}

void run_test(void(*unit_test)(), const char* name) {
    try {
        unit_test();
        printf("[+] Test %s successful.\n", name);
    } catch (const std::exception& e) {
        printf("[-] Test failure in %s. %s\n", name, e.what());
    }
}

int main() {
    printf("entering main.\n");
    run_test(initial_speed_is_zero, "initial speed is 0");
    run_test(initial_sensitivity_is_five, "initial sensitivity is 5");
    run_test(sensitivity_greater_than_1, "sensitivity greater than 1");

    /*
    AutoBrake<CarDetected> auto_brake { [&bus] (const auto& cmd) {
                                        bus.publish(cmd);
                                        }
    };
    while (true) {
        auto_brake.observe(SpeedUpdate{10L});
        auto_brake.observe(CarDetected{250L,25L});
    }
    

    assert_that(1 + 2 > 2, "something profound is wrong.\n");
    assert_that(24 == 42, "this will generate an error\n");
    */
}