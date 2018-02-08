import csv

class cumulative_perc:

  def __init__(self, country, cumulative):
    self.country = country
    self.cumulative = cumulative

  def get_country(self):
    return self.country

  def get_cumulative(self):
    return self.cumulative


f = open("oecd-gdp-pc-change-1997-2017.csv")
reader = csv.reader(f)

reader_list = list(reader)
header = reader_list[0]
data = []

n_row = len(reader_list)  # number of rows
n_col = len(header)       # number of columns

for i in range(1,n_row):
  row = reader_list[i]
  data.append(row[:])


# Question 1

max_change = 0.0
max_change_quarter = str()
max_change_country = str()
min_change = 0.0
min_change_quarter = str()
min_change_country = str()

for i in range(n_row-1):
  row = data[i]
  for j in range(1,n_col):
    if row[j] != "" :
      if float(row[j]) > max_change:
        max_change = float(row[j])
        max_change_quarter = header[j]
        max_change_country = row[0]
      elif float(row[j]) < min_change:
        min_change = float(row[j])
        min_change_quarter = header[j]
        min_change_country = row[0]

print "Max Percentage Change of ", max_change, " was in ", max_change_country, " in ", max_change_quarter
print "Min Percentage Change of ", min_change, " was in ", min_change_country, " in ", min_change_quarter


# Question 2

print "Average Percentage Change by Quarter"

quarter_n_val = []
quarter_tot = []
quarter_avg = []

for j in range(n_col-1):
  quarter_n_val.append(0)
  quarter_tot.append(0.0)
  quarter_avg.append(0.0)

for i in range(n_row-1):
  row = data[i]
  for j in range(1,n_col):
    if row[j] != "" :
      quarter_n_val[j-1] += 1
      quarter_tot[j-1] += float(row[j])

for j in range(1,n_col):
  quarter_avg[j-1] = quarter_tot[j-1]/float(quarter_n_val[j-1])
  #print header[j], ":", quarter_avg[j-1]


# Question 3

cumulative = []

for i in range(n_row-1):
  row = data[i]
  track_change = 1.0
  for j in range(1,n_col):
    if row[j] != "":
      track_change = track_change*(1.0+float(row[j])/100.0)
  cumulative.append(cumulative_perc(row[0],track_change))

for i in range(n_row-1):
  print cumulative[i].get_country(), cumulative[i].get_cumulative()


# Question 4

early_cumu = []
late_cumu = []


f.close()