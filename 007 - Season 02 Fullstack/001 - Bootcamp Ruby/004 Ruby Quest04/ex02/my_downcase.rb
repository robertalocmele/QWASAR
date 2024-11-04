# QWASAR.IO -- my_downcase
# @param {String} param_1
# @return {string}
def my_downcase(param_1)
  result = ""
  param_1.each_char do |char|
    result += char >= 'A' && char <= 'Z' ? (char.ord + 32).chr : char
  end
  result
end
