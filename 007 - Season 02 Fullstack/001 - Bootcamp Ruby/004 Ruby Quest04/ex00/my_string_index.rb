# QWASAR.IO -- my_string_index
# @param {String} param_1 (haystack)
# @param {Character} param_2 (needle)
# @return {integer}
def my_string_index(param_1, param_2)
  param_1.each_char.with_index do |char, index|
    return index if char == param_2
  end
  -1
end
