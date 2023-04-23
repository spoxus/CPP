fn main() {
    let fruit = vec!['a', 'b', 'c'];

    let buffer_overflow = fruit[4];
    assert_eq!(buffer_overflow, 'c');
    println!("Hello, world!");
}
