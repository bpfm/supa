# I have completed the given tasks below. Due to other commitments I was unable to polish up the final version. 
# I believe all the answers are correct, but I had hoped to break the code up into more usable parts. I intended 
# to seperate out the classes into seperate files for increased readability, and create a function that breaks 
# the quarters into separate columns, to remove the need for the repeated looping over the rows, as well as one 
# to actually calculate the cumulative change, reducing duplication of code.

import csv

########################################################

class csv_reader(object):

  # object that contains all functions to open and extract relevant information from a csv formatted file

  def __init__(self,filename):
    f = open(filename)            # open file
    reader = csv.reader(f)        # read all information from file
    self.reader = reader          # store 
    self.f = f
    reader_list = list(reader)
    self.header = reader_list[0]
    data = []
    n_row = len(reader_list)       # find number of rows
    n_col = len(self.header)       # find number of columns
    for i in range(1,n_row):
      row = reader_list[i]
      data.append(row[:])
    self.data = data               # store data and parameters
    self.n_row = n_row
    self.n_col = n_col

  def get_reader_list(self):       # get functions for object
    return self.reader

  def get_header(self):
    return self.header

  def get_data(self):
    return self.data

  def get_n_row(self):
    return self.n_row

  def get_n_col(self):
    return self.n_col

  def close_file(self):
    self.f.close()

########################################################

class cumulative_perc(object):

  # object to bind together a country and its corresponding cumulative percentage change

  def __init__(self, country, cumulative):
    self.country = country
    self.cumulative = cumulative

  def get_country(self):
    return self.country

  def get_cumulative(self):
    return self.cumulative

########################################################

# Open data file and read data plus associated parameters (number of rows, columns etc.)

data_from_file = csv_reader("oecd-gdp-pc-change-1997-2017.csv")

header = data_from_file.get_header()
n_row = data_from_file.get_n_row()
n_col = data_from_file.get_n_col()
data = data_from_file.get_data()

data_from_file.close_file()

# Question 1

max_change = 0.0             # set up trackers for max and min change values and positions
max_change_quarter = str()
max_change_country = str()
min_change = 0.0
min_change_quarter = str()
min_change_country = str()

for i in range(n_row-1):     # loop over every country 
  row = data[i]
  for j in range(1,n_col):               # loop over every quarter for this counrty
    if row[j] != "" :                    # skip empty entries
      if float(row[j]) > max_change:     # check if value is greater than current max value found
        max_change = float(row[j])       # update man value, along with quarter and country
        max_change_quarter = header[j]
        max_change_country = row[0]
      elif float(row[j]) < min_change:   # check if value is smaller than current min value found
        min_change = float(row[j])       # update min value, along with quarter and country
        min_change_quarter = header[j]
        min_change_country = row[0]

# Write out results for question 1

print "Max percentage change of ", max_change, " was in ", max_change_country, " in ", max_change_quarter
print "Min percentage change of ", min_change, " was in ", min_change_country, " in ", min_change_quarter
print ""


# Question 2

quarter_n_val = []  # set up empty lists to store the number of values in each column, totatl change in the column, and average for that column
quarter_tot = []
quarter_avg = []

for j in range(n_col-1):
  quarter_n_val.append(0)   # initiate elements in lists for each quarter
  quarter_tot.append(0.0)
  quarter_avg.append(0.0)

for i in range(n_row-1):        # loop over every row of data
  row = data[i]                 # extract row from data structure
  for j in range(1,n_col):      # loop over every column (except zeroth which lists the country)
    if row[j] != "" :           # skip empty entries
      quarter_n_val[j-1] += 1             # increase value counter
      quarter_tot[j-1] += float(row[j])   # add value to sum

for j in range(1,n_col):
  quarter_avg[j-1] = quarter_tot[j-1]/float(quarter_n_val[j-1])

# Write out results for question 2

print "Quarter with highest average change is ", header[quarter_avg.index(max(quarter_avg))+1] , " with ", max(quarter_avg)
print "Quarter with lowest average change is ", header[quarter_avg.index(min(quarter_avg))+1] , " with ", min(quarter_avg)
print ""


# Question 3

print "Total change by country, ordered highest change to lowest (value quoted as decimal equivalent to percentage increase, e.g. 100% increase represented by 2.0):"

cumu = []      # set up empty list for cumulative percentages for each country

for i in range(n_row-1):                                     # loop over every row
  row = data[i]                                              # extract row from data structure
  track_change = 1.0                                         # reset tracker fror each row
  for j in range(1,n_col):                                   # loop over every column
    if row[j] != "":                                         # skip empty entries
      track_change = track_change*(1.0+float(row[j])/100.0)  # update tracker using value from this column
  cumu.append(cumulative_perc(row[0],track_change))          # add country - cumulative percentage object to list

cumu.sort(key=lambda x: x.cumulative, reverse=True)          # sort list based on cumulative percentage

# Write out results for question 3

for i in range(n_row-1):
  print cumu[i].get_country(), cumu[i].get_cumulative()

print ""

# Question 4

print "Difference in change by country, ordered highest difference to lowest (same representation as above):"

early_cumu = []  # set up empty list for cumulative percentages for early and late sections for each country
late_cumu = []
comparison = []

last_early = "2006-Q4"            # set last quarter in early block

for i in range(n_row-1):          # loop over all rows
  break_found = 0                 # set break tracker to off
  track_change_early = 1.0        # set up change trackers for pre and post break
  track_change_late = 1.0
  row = data[i]                   # extract row from data structure
  for j in range(1,n_col):        # loop over all columns
    if break_found == 0:          # check if column is before break
      if row[j] != "":            # skip empty entries
        track_change_early = track_change_early*(1.0+float(row[j])/100.0)    # update early tracker using value from this column
      if header[j] == last_early: # use header to identify when break is reached
        break_found = 1           # set break tracker to on
    else:
      if row[j] != "":            # skip empty entries
        track_change_late = track_change_late*(1.0+float(row[j])/100.0)      # update late tracker using value from this column

  early_cumu.append(cumulative_perc(row[0],track_change_early))              # add country - cumulative percentage object to early list
  late_cumu.append(cumulative_perc(row[0],track_change_late))                # add country - cumulative percentage object to late list
  difference = late_cumu[i].get_cumulative()-early_cumu[i].get_cumulative()  # calculate difference between late and early cumulative percentage change
  comparison.append(cumulative_perc(row[0],difference))                      # append differnce with ountry

comparison.sort(key=lambda x: x.cumulative, reverse=True)

# Write out results for question 4

for i in range(n_row-1):
  print comparison[i].get_country(), comparison[i].get_cumulative()
