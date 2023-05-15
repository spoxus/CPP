#[derive(Debug)]

enum Cereal {
    Barley, Millet, Rice,
    Rhe, Spelt, Wheat,
}

fn main() {
    println!("Hello, world!");
    let mut grains: Vec<Cereal> = vec![];
    grains.push(Cereal::Rhe);
    drop(grains);
    println!("{:?}", grains);
}
