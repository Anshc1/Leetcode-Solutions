# Write your MySQL query statement below
SELECT students.student_id, students.student_name, Subjects.subject_name,
       CASE WHEN COUNT(Examinations.student_id) IS NULL THEN 0
            ELSE COUNT(Examinations.student_id)
       END AS attended_exams
FROM students
CROSS JOIN Subjects
LEFT JOIN Examinations ON students.student_id = Examinations.student_id AND Subjects.subject_name = Examinations.subject_name
GROUP BY students.student_id, Subjects.subject_name
ORDER BY students.student_id, Subjects.subject_name;
