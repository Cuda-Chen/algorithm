Max = 10000

def merge(array, left, mid, right)
    left_side = array[left..mid]
    right_side = array[(mid + 1)..right]

    left_side << Max
    right_side << Max

    left_idx, right_idx = 0, 0

    (left..right).each { |i|
        if left_side[left_idx] < right_side[right_idx]
            array[i] = left_side[left_idx]
            left_idx += 1
        else
            array[i] = right_side[right_idx]
            right_idx += 1
        end
    }
end

def merge_sort(array, left, right)
    if left < right
        mid = (left + right) / 2;
        merge_sort(array, left, mid)
        merge_sort(array, mid + 1, right)
        merge(array, left, mid, right)
    end
end

def print_array(array)
    array.each do |num|
        print num, " "
    end
    puts

    nil
end

arr = [5, 3, 8, 6, 2, 7, 1, 4]
print "original: ", "\n"
print_array(arr)

merge_sort(arr, 0, arr.size - 1)
print "sorted: ", "\n"
print_array(arr)
