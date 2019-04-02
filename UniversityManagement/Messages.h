#pragma once
#include "stdafx.h"
#include"Parent.h"
int WriteMessageP2T(Parent* p);
int WriteMessageT2P(Teacher* t);
int WriteMessageT2S(Teacher* t);
int ReadStudentMessages(Student* s);
int ReadParentMessages(Parent* p);
int ReadTeacherMessages(Teacher* t);

