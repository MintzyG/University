fn main() {
    let arr = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19];
    let target = 1;

    if let Some(index) = binary_search(&arr, target) {
        println!("Element {} found at index {}", target, index);
    } else {
        println!("Element {} not found in the array", target);
    }
}

fn binary_search(arr: &[i32], target: i32) -> Option<usize> {
    let mut left = 0;
    let mut right = arr.len() - 1;

    while left <= right {
        let mid = left + (right - left) / 2;
        if arr[mid] == target {
            return Some(mid);
        } else if arr[mid] < target {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    None
}


