# QWASAR.IO -- my_map_mult_two
# @param {Integer[]} param_1
# @return {integer[]}
def my_map_mult_two(param_1)
  result = []
  index = 0
  while index < param_1.length
    result << param_1[index] * 2
    index += 1
  end
  result
end
