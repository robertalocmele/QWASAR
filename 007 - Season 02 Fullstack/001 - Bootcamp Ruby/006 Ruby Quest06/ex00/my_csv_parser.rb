# QWASAR.IO -- my_csv_parser
# @param {String} param_1
# @param {String} param_2
# @return {string[][]}
def my_csv_parser(param_1, param_2)
  # Split the input string into lines based on the newline character
  lines = param_1.split("\n")
  
  # Initialize an empty array to hold the result
  result = []

  # Iterate through each line
  lines.each do |line|
    # Split each line into columns based on the separator
    values = line.split(param_2)
    # Append the array of values to the result
    result << values
  end
  
  result
end
