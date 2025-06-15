use rand::{distributions::Alphanumeric, Rng};

fn generate_password(length: usize) -> String {
    rand::thread_rng()
        .sample_iter(&Alphanumeric)
        .take(length)
        .map(char::from)
        .collect()
}

fn main() {
    let password_length = 12; // Nastav požadovanou délku hesla
    let password = generate_password(password_length);
    println!("Vygenerované heslo: {}", password);
}