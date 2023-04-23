#include <functional>
#include <stdexcept>

using std::function;
using std::exception;

constexpr void assert_that(bool statmenet, const char* message) {
    if (!statmenet) throw std::runtime_error{message};
}

void run_test(void(*unit_test)(), const char* name) {
    try {
        unit_test();
        printf("[+] Test %s successful.\n", name);
    } catch (const std::exception& e) {
        printf("[-] Test failure in %s. %s.\n", name, e.what());
    }
}

struct SpeedUpdate {
    double velocity_mps;
};

struct CarDetected {
    double distance;
    double velocity_mps;
};

struct BrakeCommand {
    double time_to_collision;
};

using SpeedUpdateCallback = function<void(const SpeedUpdate&)>;
using CarDetectedCallback = function<void(const CarDetected&)>;

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

struct ServiceBus {
    void publish(const BrakeCommand&) {}
};

//template <typename T>
struct AutoBrake {
    AutoBrake(ServiceBus& bus) : collision_threshold_s{5}, speed_mps{} {}
    //void observe(const SpeedUpdate& su) {}
    //void observe(const CarDetected& cd) {}
    void set_collision_threshold_s(double s) {
        if (s < 1) throw exception{};
        collision_threshold_s = s;
    }
    double get_collision_threshold_s() const {return collision_threshold_s;}
    double get_speed_mps() const {return speed_mps;}
private:
    double collision_threshold_s;
    double speed_mps;
};

void init_speed_is_zero() {
    ServiceBus bus{};
    AutoBrake brake {bus};
    assert_that(brake.get_speed_mps() == 0L, "speed is not equal to 0.");
}

void initial_sensitivity_is_five() {
    ServiceBus bus{};
    AutoBrake brake {bus};
    assert_that(brake.get_collision_threshold_s() == 5L, "sensitivity is not five");
}

void sensitivity_greater_than_1() {
    ServiceBus bus{};
    AutoBrake brake {bus};
    try {
        brake.set_collision_threshold_s(0.5L);
    } catch (const exception&) {
        return;
    }
    assert_that(false, "no exception thrown.");
}

int main() {
    assert_that(3 > 2, "what?");
    run_test(init_speed_is_zero, "init speed is zero.");
    run_test(initial_sensitivity_is_five, "initial sensitivity is 5");
    run_test(sensitivity_greater_than_1, "sensitivity > 1");
}