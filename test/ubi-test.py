from ubidots import ApiClient
import random

#Create an "API" object

api = ApiClient("1111d9b0dbf07d9c4d90fa5de3b4cce131626ead")

#Create a "Variable" object

test_variable = api.get_variable("5885045d7625422b12422708")

#Here is where you usually put the code to capture the data, either through your GPIO pins or as a calculation. We'll simply put a random value here:

temps_allumage = random.randint(1,24)
consommation_bulb = 9 #L'ampoule consomme 9 watts
energie_consommee = temps_allumage * consommation_bulb
#Write the value to your variable in Ubidots

test_variable.save_value({'value': energie_consommee})

