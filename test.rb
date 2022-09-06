for i in 1..1000 do
	puts "Number of elements: #{i}"
	for j in 1..3 do
		var = (1..i).to_a.shuffle.join(' ')
		system("./push_swap " + var + " >.moves")
		print "Test #{j}:  Moves: "
		system("cat .moves | wc -l | tr -d ' ' | tr '\n' ' '")
		print "  Checker: "
		system("cat .moves | ./checker " + var)
	end
	puts 
end
system("rm -f .moves")