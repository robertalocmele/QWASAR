# QWASAR.IO -- my_is_sort
# @param {Integer[]} param_1
# @return {boolean}
def my_is_sort(param_1)
  return true if param_1.empty? || param_1.length == 1

  ascending = true
  descending = true

  (1...param_1.length).each do |i|
    ascending = false if param_1[i] < param_1[i - 1]
    descending = false if param_1[i] > param_1[i - 1]
  end

  ascending || descending
end
