import pandas as pd
import numpy as np
from datetime import date

travel_expense = pd.read_csv('C:\psp games\employees.csv')
todays_date = date.today()
travel_expense[todays_date] = "0"
#where 50 is no. of employees
eid = int(input('Enter your employee_id:'))
expense_type = input('enter the expense type:')
amount = int(input("enter the amount:"))
index = eid-100
if expense_type == 'travel' and travel_expense.loc[index]['DISIGNATION'] == 'Manager':
    if travel_expense.isnull(travel_expense.iloc[index]['LAST_T']) :
        travel_expense.loc[index]['LAST_T'] == todays_date

print(travel_expense.loc[index])
#book.to_csv('C:\psp games\employees.csv')
