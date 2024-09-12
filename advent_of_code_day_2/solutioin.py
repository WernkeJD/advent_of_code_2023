num_blues = 14
num_greens = 13
num_reds = 12

sum = 0

with open("probability.txt") as my_file:
    x = 1

    for line in my_file:
        scentence = line.split()
        print(f'starting to look at game: {x}')
        print(scentence)

        for i, word in enumerate(scentence):
            if word == 'green' or word == 'green,' or word == 'green;':
                if int(scentence[i-1]) > num_greens:
                    break

            elif word == "blue," or word == 'blue' or word == 'blue;':
                if int(scentence[i-1]) > num_blues:
                    break
                
            elif word == "red," or word == 'red' or word == 'red;':
                if int(scentence[i-1]) > num_reds:
                    break
            else:
                if (len(scentence) - 2) == i:
                    print(f'game {x} possible')
                    sum+=x
                    print(f'current sum {sum}')

                else:
                    pass

        x+=1

print(sum)