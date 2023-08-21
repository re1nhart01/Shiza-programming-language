use std::{fs::{self, ReadDir}, io::Read, path::{Path, PathBuf}, env, fmt::format, collections::HashMap};


pub trait IShizaFS {
    fn new() -> Self;
    fn bulk_read(&self, path: String, filename: Vec<String>) -> Vec<FileData<String>>;
    fn read(&self, filename: &str) -> String;
    fn bulk_write(filename: &str);
    fn write(filename: &str, content: Vec<u8>);
    fn delete(filename: &str);
    fn write_output_file(content: Vec<u8>);
    fn generate_file_folder_structure(&self, folder: &str) -> Vec<String>;
    fn is_exists_main_file() -> bool;
}

pub const OutputFile: &str = "shiza.asm";

pub struct FileData<T> {
    pub name: String,
    pub content: T
} 

pub type TShizaFile = Vec<FileData<Vec<u8>>>; 

pub fn get_current_working_dir() -> String {
    return env::current_dir().unwrap().into_os_string().into_string().unwrap();
}

pub struct ShizaFS {}

impl IShizaFS for ShizaFS {
    fn bulk_read(&self, path: String, filenames: Vec<String>) -> Vec<FileData<String>>{
        let mut result: Vec<FileData<String>> = Vec::new();
        for file in filenames {
            let fileCont: String = self.read(&format!("{}{}", path, file));
            assert_ne!(fileCont, "", "[SHIZA Error]: File is empty");
            let empty_struct = FileData{
                content: fileCont,
                name: file,
            };
            result.push(empty_struct)
        }
        return result;
    }

    fn read(&self, filename: &str) -> String {
        assert!(filename.len() >= 4, "[SHIZA Error]: Can not find this file");
        println!("Currently reading file: {}", filename);
        let contents = fs::read_to_string(format!("{}{}", get_current_working_dir().to_string(), filename)).unwrap();
        return contents;
    }

    fn bulk_write(filename: &str) {
        todo!()
    }

    fn write(filename: &str, content: Vec<u8>) {
        todo!()
    }

    fn delete(filename: &str) {
        todo!()
    }

    fn write_output_file(content: Vec<u8>) {
        todo!()
    }

    fn generate_file_folder_structure(&self, folder: &str) -> Vec<String> {
        assert!(folder != "");
        let path = get_current_working_dir().to_string();
        let paths = fs::read_dir(format!("{}{}{}", path, "/src", "/playground")).unwrap();
          
          let names =
          paths.filter_map(|entry| {
            entry.ok().and_then(|e|
              e.path().file_name()
              .and_then(|n| n.to_str().map(|s| String::from(s)))
            )
          }).collect::<Vec<String>>();
          return names;
    }

    fn is_exists_main_file() -> bool {
        todo!()
    }

    fn new() -> ShizaFS {
        return ShizaFS {}
    }
}
