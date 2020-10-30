import string
import random

characters = string.ascii_letters + string.punctuation  + string.digits
password =  "".join(random.choice(characters) for x in range(random.randint(8, 16)))

print('')
print('Generating...')
print(password)
