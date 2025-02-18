import csv

# full_dataset2 = csv.DictReader(open("insurance_v1.csv"))

ages = []
sexs = []
bmis = []
num_children = []
smokers = []
regions = []
insurance_charges = []
full_dataset = []

with open("insurance_v1.csv") as dataset_file:
	for row in csv.DictReader(dataset_file):
		ages.append(int(row["age"]))
		sexs.append(row["sex"])
		bmis.append(float(row["bmi"]))
		num_children.append(int(row["children"]))
		smokers.append(row["smoker"])
		regions.append(row["region"])
		insurance_charges.append(float(row["charges"]))
		full_dataset.append(row)


# for row in full_dataset2:
# 	ages.append(int(row["age"]))
# 	sexs.append(row["sex"])
# 	bmis.append(float(row["bmi"]))
# 	num_children.append(int(row["children"]))
# 	smokers.append(row["smoker"])
# 	regions.append(row["region"])
# 	insurance_charges.append(float(row["charges"]))

# for row in full_dataset:
# 	print(row)



def average(list):
	total_elements = len(list)
	sum_values = 0
	for value in list:
		sum_values += value
	return sum_values / total_elements


def percentage_present(list, element):
	total_elements = len(list)
	count_element = 0
	for value in list:
		if value == element:
			count_element += 1
	return count_element / total_elements * 100

def find_simple_elements(field, list, value):
	count_values = 0
	for item in list:
		if item == value:
			count_values += 1
	print("there are {} individuals with {} years.".format(count_values, value))
	values = []
	for row in full_dataset:
		if row[field] == str(value):
			values.append(row)
			count_values -= 1
			if count_values == 0:
				return values


def find_cross_elements(fields, lists, value_list):
	count_values = 0
	tmp_list = []
	for list in lists:
		if 


# what to get:
# -- average age
# -- max age
# -- min age
# -- percentage per sex
# -- average bmi
# -- max children
# -- average children
# -- average smokers
# -- percentage per region
# -- average insurance charges
# -- max insurance charges
# -- min insurance charges
# -- relationships between data

print("""While the youngest individual of the dataset is {youngest} years old and the oldest has {oldest} years, the average age of the dataset is {average_age:.2f} years old."""
	  .format(average_age=average(ages), youngest=min(ages), oldest=max(ages)))

percentage_men = percentage_present(sexs, "male")
print("The dataset is made of {males:.2f}% males and {females:.2f}% females."
	  .format(males=percentage_men, females=(100-percentage_men)))

print("There's a percentage of {:.2f}% non-smokers in the dataset."
	  .format(percentage_present(smokers, "no")))

print(find_elements("age", ages, 18))

print(percentage_present(regions, "northwest"))

print(max(num_children))


