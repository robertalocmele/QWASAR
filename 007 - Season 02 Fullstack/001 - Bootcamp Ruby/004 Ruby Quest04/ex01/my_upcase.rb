# QWASAR.IO -- my_upcase
# @param {String} param_1
# @return {string}
def my_upcase(param_1)
  result = ""
  param_1.each_char do |char|
    result += char >= 'a' && char <= 'z' ? (char.ord - 32).chr : char
  end
  result
end
