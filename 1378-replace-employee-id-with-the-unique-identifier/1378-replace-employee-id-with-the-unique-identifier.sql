# Write your MySQL query statement below
# select 
# eu.unique_id ,e.name 
# from employees e left join employeeuni eu on e.id=eu.id;
select 
eu.unique_id as unique_id, e.name as name
from Employees e left join EmployeeUNI eu on e.id = eu.id