# QWASAR.IO -- my_size
# @param {String} param_1
# @return {integer}
def my_size(param_1)
  length = 0
  param_1.each_char { length += 1 }
  length
end
