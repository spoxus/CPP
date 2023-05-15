fn greet_world() {
    println!("hello world!");
    let southern_germany = "HHH";
    let japan = "SIDS";
    let regions = [southern_germany, japan];
    for region in regions.iter() {
        println!("{}", &region);
    }
}

fn main() {
    greet_world();
}