#include <cstdio>

struct RatThing {
  static int thread_local rat_things_power;
  void power_up_rat_thing(int nuclear_isotopes) {

    printf("static var power = %d\n", rat_things_power);
    rat_things_power += nuclear_isotopes;
    const auto waste_heat = rat_things_power * 20;
    printf("waste heat = %d * %d = %d\n", rat_things_power, 20, waste_heat);
    if (waste_heat > 10'000)
      printf("warning! hot doggie!\n");
  }
};

int thread_local RatThing::rat_things_power = 200;

int main() {
    
    RatThing rat;
    rat.power_up_rat_thing(100);
    rat.power_up_rat_thing(500);

}