use rand::Rng;
use std::cmp::Ordering;
use std::io;

/*
 * can i use comment this way
 */
fn main() {
    println!("guess the number!");
    let secret_number = rand::thread_rng().gen_range(1, 101);
    //println!("the secret number is {}", secret_number);
    loop {
        println!("please input your guess");

        let mut guess = String::new();

        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
        println!("you guessed: {}", guess);

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too Small"),
            Ordering::Greater => println!("Too big"),
            Ordering::Equal => {
                println!("You won");
                break;
            }
        }
    }
}
