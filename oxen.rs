
use std::fs::{self, File};
use std::io::{self, Write, Read};

let mut Dir = "Desktop";

fn clear_screen() {
    if cfg!(target_os = "windows") {
        std::process::Command::new("cmd")
            .args(&["/C", "cls"])
            .status()
            .unwrap();
    } else {
        std::process::Command::new("clear")
            .status()
            .unwrap();
    }
}

fn listf() {
    let paths = fs::read_dir(".").unwrap();
    for path in paths {
        println!("{}", path.unwrap().path().display());
    }
}

fn newdirf() -> std::io::Result<()> {
    println!("What will the Folder/Directory name be:");
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let input = input.trim();
    fs::create_dir(input)?;
    Ok(())
}

fn printdir(){
    println!("DIR:{}", Dir);
}
fn movetodir(){
    println!("What dir do you want to go to:");
    let mut cjh;
    io::stdin().read_line(&mut cjh).unwrap();
    match cjh.trim() {
        "Desktop" => { let mut Dir = "Desktop"; }
        "Dev" => { let mut Dir = "Dev"}
    }
}
fn start() {
    clear_screen();
    println!("RUST NOVA");
    println!("[User1:{}]$", Dir);
    let mut cmd;
    io::stdin().read_line(&mut cmd).unwrap();
    match cmd.trim() {
        "clear" => {
            clear_screen();
        }
        "ls" => {
            listf();
        }
        "make_dir" => {
            if let Err(e) = newdirf() {
                println!("Error creating directory: {}", e);
            }
        }
        "goto_dir" => { movetodir(); }
        "cur_dir" => { printdir(); }
        _ => {
            println!("Unknown command.");
        }
    }
    start();
}

fn login() {
    println!("What will your UNIX name be:");
    let mut unix_name = String::new();
    io::stdin().read_line(&mut unix_name).unwrap();
    let mut name_file = File::create("name.txt").expect("creation failed");
    name_file.write_all(unix_name.trim().as_bytes()).expect("write failed");
    
    println!("What will your UNIX password be:");
    let mut unix_password = String::new();
    io::stdin().read_line(&mut unix_password).unwrap();
    let mut password_file = File::create("password.txt").expect("creation failed");
    password_file.write_all(unix_password.trim().as_bytes()).expect("write failed");

    clear_screen();
    start();
}

fn setup() {
    println!("What is your UNIX name:");
    let mut input_name = String::new();
    io::stdin().read_line(&mut input_name).unwrap();
    
    let mut name_file = File::open("name.txt").expect("could not open name file");
    let mut stored_name = String::new();
    name_file.read_to_string(&mut stored_name).expect("could not read name file");
    
    if input_name.trim() == stored_name.trim() {
        println!("What is your UNIX password:");
        let mut input_password = String::new();
        io::stdin().read_line(&mut input_password).unwrap();
        
        let mut password_file = File::open("password.txt").expect("could not open password file");
        let mut stored_password = String::new();
        password_file.read_to_string(&mut stored_password).expect("could not read password file");
        
        if input_password.trim() == stored_password.trim() {
            start();
        } else {
            println!("Incorrect password.");
        }
    } else {
        println!("Incorrect name.");
    }
}

fn main() {
    println!("Login or Setup");
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    match input.trim() {
        "Setup" => {
            login();
        }
        "Login" => {
            setup();
        }
        _ => {
            println!("Invalid option.");
        }
    }
}

