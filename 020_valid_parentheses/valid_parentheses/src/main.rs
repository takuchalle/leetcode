pub fn is_valid(s: String) -> bool {
    if s.is_empty() {
        return true;
    }

    let mut stack = vec![];
    for c in s.chars() {
        match c {
            '(' | '{' | '[' => stack.push(c),
            ')' => match stack.pop() {
                Some(c) => {
                    if c != '(' {
                        return false;
                    }
                }
                None => return false,
            },
            ']' => match stack.pop() {
                Some(c) => {
                    if c != '[' {
                        return false;
                    }
                }
                None => return false,
            },
            '}' => match stack.pop() {
                Some(c) => {
                    if c != '{' {
                        return false;
                    }
                }
                None => return false,
            },
            _ => return false,
        }
    }

    stack.is_empty()
}

fn main() {
    assert_eq!(true, is_valid("()".to_owned()));
    assert_eq!(true, is_valid("()[]{}".to_owned()));
    assert_eq!(false, is_valid("(]".to_owned()));
    assert_eq!(false, is_valid("([)]".to_owned()));
    assert_eq!(true, is_valid("{[]}".to_owned()));
}
