# Write your MySQL query statement below

select st.student_id as student_id, st.student_name as student_name,
sb.subject_name as subject_name, count(ex.subject_name) as attended_exams
from Students st join Subjects sb left join Examinations ex on st.student_id = ex.student_id and sb.subject_name = ex.subject_name
group by st.student_id, st.student_name,sb.subject_name
order by student_id, subject_name;



