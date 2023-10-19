use std::fmt;

// Tuples can be used as function arguments and as return values.
#[wa
rn(dead_code)]
fn reverse(pair: (f64, f64)) -> (f64, f64) {
    // `let` can be used to bind the members of a tuple to variables.
    let (n1,n2) = pair;

    (n2, n1)
}

fn transpose(m: Matrix) -> Matrix {
    let Matrix(a11, a12, a21, a22) = m;

    Matrix(a11, a21, a12, a22)
    // Matrix(m.0, m.2, m.1, m.3)
}

impl fmt::Display for Matrix {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "( {} {} )\n( {} {} )", self.0, self.1, self.2, self.3)
    }
}


// The following struct is for the activity.
#[derive(Debug)]
struct Matrix(f64, f64, f64, f64);



fn main() {
    let matrix = Matrix(1.1, 1.2, 2.1, 2.2);
    println!("{}", matrix);
    println!("{}", transpose(matrix));
}