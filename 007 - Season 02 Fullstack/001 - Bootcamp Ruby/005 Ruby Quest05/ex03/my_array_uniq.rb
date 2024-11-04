# QWASAR.IO -- my_array_uniq
# @param {Integer[]} param_1
# @return {integer[]}
def my_array_uniq(param_1)
  unique_elements = []
  param_1.each do |element|
    unique_elements << element unless unique_elements.include?(element)
  end
  unique_elements
end
