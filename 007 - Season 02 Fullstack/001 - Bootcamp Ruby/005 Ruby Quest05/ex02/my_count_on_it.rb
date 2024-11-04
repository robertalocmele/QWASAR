# QWASAR.IO -- my_count_on_it
# @param {String[]} param_1
# @return {integer[]}
def my_count_on_it(param_1)
  result = []
  index = 0
  while index < param_1.length
    result << param_1[index].length
    index += 1
  end
  result
end
