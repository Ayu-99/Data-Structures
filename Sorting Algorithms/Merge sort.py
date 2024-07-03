def merge(array, left, mid, right):
    subArrayOne = mid - left + 1
    subArrayTwo = right - mid

    leftArray = [0] * subArrayOne
    rightArray = [0] * subArrayTwo

    for i in range(subArrayOne):
        leftArray[i] = array[left + i]
    for j in range(subArrayTwo):
        rightArray[j] = array[mid + 1 + j]

    indexOfSubArrayOne = 0  
    indexOfSubArrayTwo = 0 
    indexOfMergedArray = left

    while indexOfSubArrayOne < subArrayOne and indexOfSubArrayTwo < subArrayTwo:
        if leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]:
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne]
            indexOfSubArrayOne += 1
        else:
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo]
            indexOfSubArrayTwo += 1
        indexOfMergedArray += 1

    while indexOfSubArrayOne < subArrayOne:
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne]
        indexOfSubArrayOne += 1
        indexOfMergedArray += 1

    while indexOfSubArrayTwo < subArrayTwo:
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo]
        indexOfSubArrayTwo += 1
        indexOfMergedArray += 1

def mergeSort(array, begin, end):
    if begin >= end:
        return

    mid = begin + (end - begin) // 2
    mergeSort(array, begin, mid)  // 2 4 5
    mergeSort(array, mid + 1, end) // 1 3
    merge(array, begin, mid, end) //1 2 3 4 5

def printArray(array, size):
    for i in range(size):
        print(array[i], end=" ")
    print()

if __name__ == "__main__":
    arr = [12, 11, 13, 5, 6, 7]
    arr_size = len(arr)

    print("Given array is")
    printArray(arr, arr_size)

    mergeSort(arr, 0, arr_size - 1)

    print("\nSorted array is")
    printArray(arr, arr_size)
