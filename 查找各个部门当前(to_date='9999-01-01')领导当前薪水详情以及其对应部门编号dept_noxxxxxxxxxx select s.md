- 查找各个部门当前(to_date='9999-01-01')领导当前薪水详情以及其对应部门编号dept_no。部门领导的薪水就是员工编号在领导表中的员工的薪水

  ```sql
  select s.* ,d.dept_no
  from salaries as s join dept_manager as d
  on s.emp_no=d.emp_no
  where s.to_date='9999-01-01' and d.to_date='9999-01-01'
  ```

- 查找所有已经分配部门的员工的last_name和first_name。已分配部门意思就是在部门表中也有这个员工编号。

```sql
select emp.last_name , emp.first_name,d.dept_no
from employees as emp join dept_emp as d
on emp.emp_no=d.emp_no
```

- 查找所有员工的last_name和first_name以及对应部门编号dept_no，也**包括展示没有分配具体**部门的员工。left join确保on左边的都出现，不管右边的有没有对应。left join应该配合on使用。on在临时表之前过滤，where在临时表之后过滤。[on-vs-where](https://stackoverflow.com/questions/354070/sql-join-where-clause-vs-on-clause)

  ```sql
  select emp.last_name , emp.first_name,d.dept_no
  from employees as emp  left join dept_emp as d
  on emp.emp_no=d.emp_no
  ```

