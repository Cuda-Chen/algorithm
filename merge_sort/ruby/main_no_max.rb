# this version does not use MAX value to indicate the end of subarray

def merge!(array, left, mid, right)
    left_most_value = mid - left + 1
    right_most_value = right - mid
    left_side = array[left..mid]
    right_side = array[(mid + 1)..right]

    left_idx = right_idx = 0
    k = left
    while left_idx < left_most_value && right_idx < right_most_value
        if left_side[left_idx] < right_side[right_idx]
            array[k] = left_side[left_idx]
            left_idx += 1
        else
            array[k] = right_side[right_idx]
            right_idx += 1
        end

        k += 1
    end

    # copy the remaining elements of left_side[]
    while left_idx < left_most_value
        array[k] = left_side[left_idx]
        left_idx += 1
        k += 1
    end
    # copy the remaining elements of right_side[]
    while right_idx < right_most_value
        array[k] = right_side[right_idx]
        right_idx += 1
        k += 1
    end
end

def merge_sort!(array, left, right)
    return unless left < right
    mid = (left + right) / 2
    merge_sort! array, left, mid
    merge_sort! array, mid + 1, right
    merge! array, left, mid, right
end

def print_array(array)
    puts array.join ' '
end

arr = [5, 3, 8, 6, 2, 7, 1, 4]
print "original: ", "\n"
print_array arr

merge_sort! arr, 0, arr.size - 1 
print "sorted: ", "\n"
print_array arr 
