pub fn sort(mut v: Vec<i32>) -> Vec<i32> {
    let n = v.len();
    for i in 1..n {
        let mut j = i;
        while j > 0 && v[j] < v[j - 1] {
            v.swap(j, j - 1);
            j -= 1;
        }
    }
    v
}

fn maina() {
    let v = vec![5, 2, 4, 6, 1, 3];
    println!("Original vector: {:?}", v);
    let sorted_v = sort(v);
    println!("Sorted vector: {:?}", sorted_v);
}
