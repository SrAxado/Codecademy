#  This is the U.S. Medical Insurance Costs project 
# from Codecademy's "Data Scientist Analytics" Carreer Path
# (the dataset used is the Kaggle's version 1 dataset, downloaded 2025/02/18)
# (https://www.kaggle.com/datasets/mirichoi0218/insurance/data)
import csv

ages = []
sexs = []
bmis = []
num_children = []
smokers = []
regions = []
insurance_charges = []
full_dataset = []

# fills all the singular data list as well as the full_dataset dictionary
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


# calculates the average value from a list
def average(list):
	total_elements = len(list)
	sum_values = 0
	for value in list:
		sum_values += value
	return sum_values / total_elements

# calculates the percentage of the presence of a value in a list
def percentage_present(list, element):
	total_elements = len(list)
	count_element = 0
	for value in list:
		if value == element:
			count_element += 1
	return count_element / total_elements * 100

# returns a list of all the rows of a dataset that have a specific value in its field
# (the passed as argument "list" serves as fast and light way to assess if there's the desired information)
def find_simple_elements(field, value, dataset, list):
	count_values = 0
	for item in list:
		if item == value:
			count_values += 1
	# print("there are {} individuals with {} years.".format(count_values, value))
	values = []
	for row in dataset:
		if row[field] == str(value):
			values.append(row)
			count_values -= 1
			if count_values == 0:
				return values

def item_valid(field, value, item):
	if field in ["age", "bmi", "children", "charges"]:
		if type(value) == list or type(value) == tuple:
			min_value = value[0]
			max_value = value[1]
			return item >= min_value and item <= max_value
	else:
		return value == item

# returns a list of all the rows of a dataset that have specific values in specific fields
# ===> (this is a powerfull function, as it can narrow down the dataset to fullfill all the desired conditions) <===
# -- for fields of numerical values "values_list" can assume a single value or [min, max] list or (min, max) tuple
## -- the passed as argument list of "lists" is a fast and light way to assess the desired search conditions
## -- if one wants to use a subset of the full_dataset, one has to adjust the lists to check
def cross_reference_elements(fields_list, values_list, dataset, lists):
	if len(fields_list) != len(values_list) or len(fields_list) != len(lists):
		print("The number of fields to search for does not match the number of values to search and/or the lists to search in")
		exit
	count_values = 0
	tmp_list = {}
	list_idx = 0
	for list in lists:
		item_idx = 0
		value_to_search = values_list[list_idx]
		for item in list:
			if item_valid(fields_list[list_idx], value_to_search, item):
				# append the item index in the list if it was already create ELSE create it
				if list_idx in tmp_list.keys():
					tmp_list[list_idx].append(item_idx)
				else:
					tmp_list[list_idx] = [item_idx]
			item_idx += 1
		list_idx += 1
	# convert to a set in order to detect the unique elements of all the condition lists
	common_elements = set(tmp_list[0])
	for idx in range(1,len(tmp_list)):
		common_elements.intersection_update(set(tmp_list[idx]))

	common_elements = [*common_elements]
	common_elements.sort()
	
	final_list = [dataset[item_idx] for item_idx in common_elements]
	# print(final_list)
	return final_list
	


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

young_18_old = find_simple_elements("age", 18, full_dataset, ages)
print("The presence of 18 years old people in the dataset is {:.2f}%.".format(len(young_18_old)/len(ages)*100))

young_male_smoker_parents = cross_reference_elements(["age", "sex", "smoker", "children"], [(18, 35), "male", "yes", (1, 10)], full_dataset, [ages, sexs, smokers, num_children])
young_male_non_smoker_parents = cross_reference_elements(["age", "sex", "smoker", "children"], [(18, 35), "male", "no", (1, 10)], full_dataset, [ages, sexs, smokers, num_children])
# young_male_parents = cross_reference_elements(["age", "sex", "children"], [(18, 35), "male", (1, 10)], full_dataset, [ages, sexs, num_children])
print("The presence of young male parents (ages 18-35) in the dataset is {perc_ymsp:.2f}%  are smokers and {perc_ymnsp:.2f}% are non-smokers"
	#   .format(perc_ymsp=(len(young_male_smoker_parents)/len(young_male_parents) * 100), perc_ymnsp=(len(young_male_non_smoker_parents)/len(young_male_parents) * 100)))
	  .format(perc_ymsp=(len(young_male_smoker_parents)/(len(young_male_smoker_parents) + len(young_male_non_smoker_parents)) * 100), 
		   perc_ymnsp=(len(young_male_non_smoker_parents)/(len(young_male_smoker_parents) + len(young_male_non_smoker_parents)) * 100)))

print("The dataset has a percentage of {:.2f}% of northwest people.".format(percentage_present(regions, "northwest")))

print("The max number of children that a parent has in the dataset is {}.".format(max(num_children)))


