i = 0
print "Enter a number: "
j = gets.to_f
k = (j + 13) / 27.0

while k < 10
  k += 1
  i = 3 * k - 1
  puts "i: #{i}"
  puts "k: #{k}"
  puts "j: #{j}"
  puts
end