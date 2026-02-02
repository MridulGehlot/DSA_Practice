def containsDuplicates(numbers):
	return len(numbers)!=len(set(numbers))
print(containsDuplicates([1,2,3,4,5]))
print(containsDuplicates([1,2,3,1,5]))
