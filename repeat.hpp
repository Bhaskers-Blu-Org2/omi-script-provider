// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT license.
#ifndef INCLUDED_REPEAT_HPP
#define INCLUDED_REPEAT_HPP


#define _REPEAT0(m)
#define _REPEAT1(m) m(0)
#define _REPEAT2(m) m(0) m(1)
#define _REPEAT3(m) _REPEAT2(m) m(2)
#define _REPEAT4(m) _REPEAT3(m) m(3)
#define _REPEAT5(m) _REPEAT4(m) m(4)
#define _REPEAT6(m) _REPEAT5(m) m(5)
#define _REPEAT7(m) _REPEAT6(m) m(6)
#define _REPEAT8(m) _REPEAT7(m) m(7)
#define _REPEAT9(m) _REPEAT8(m) m(8)
#define _REPEAT10(m) _REPEAT9(m) m(9)
#define _REPEAT11(m) _REPEAT10(m) m(10)
#define _REPEAT12(m) _REPEAT11(m) m(11)
#define _REPEAT13(m) _REPEAT12(m) m(12)
#define _REPEAT14(m) _REPEAT13(m) m(13)
#define _REPEAT15(m) _REPEAT14(m) m(14)
#define _REPEAT16(m) _REPEAT15(m) m(15)
#define _REPEAT17(m) _REPEAT16(m) m(16)
#define _REPEAT18(m) _REPEAT17(m) m(17)
#define _REPEAT19(m) _REPEAT18(m) m(18)
#define _REPEAT20(m) _REPEAT19(m) m(19)
#define _REPEAT21(m) _REPEAT20(m) m(20)
#define _REPEAT22(m) _REPEAT21(m) m(21)
#define _REPEAT23(m) _REPEAT22(m) m(22)
#define _REPEAT24(m) _REPEAT23(m) m(23)
#define _REPEAT25(m) _REPEAT24(m) m(24)
#define _REPEAT26(m) _REPEAT25(m) m(25)
#define _REPEAT27(m) _REPEAT26(m) m(26)
#define _REPEAT28(m) _REPEAT27(m) m(27)
#define _REPEAT29(m) _REPEAT28(m) m(28)
#define _REPEAT30(m) _REPEAT29(m) m(29)
#define _REPEAT31(m) _REPEAT30(m) m(30)
#define _REPEAT32(m) _REPEAT31(m) m(31)
#define _REPEAT33(m) _REPEAT32(m) m(32)
#define _REPEAT34(m) _REPEAT33(m) m(33)
#define _REPEAT35(m) _REPEAT34(m) m(34)
#define _REPEAT36(m) _REPEAT35(m) m(35)
#define _REPEAT37(m) _REPEAT36(m) m(36)
#define _REPEAT38(m) _REPEAT37(m) m(37)
#define _REPEAT39(m) _REPEAT38(m) m(38)
#define _REPEAT40(m) _REPEAT39(m) m(39)
#define _REPEAT41(m) _REPEAT40(m) m(40)
#define _REPEAT42(m) _REPEAT41(m) m(41)
#define _REPEAT43(m) _REPEAT42(m) m(42)
#define _REPEAT44(m) _REPEAT43(m) m(43)
#define _REPEAT45(m) _REPEAT44(m) m(44)
#define _REPEAT46(m) _REPEAT45(m) m(45)
#define _REPEAT47(m) _REPEAT46(m) m(46)
#define _REPEAT48(m) _REPEAT47(m) m(47)
#define _REPEAT49(m) _REPEAT48(m) m(48)
#define _REPEAT50(m) _REPEAT49(m) m(49)


#define _REPEAT(n) _REPEAT##n
#define REPEAT(n,m) _REPEAT(n) (m)


#endif // INCLUDED_REPEAT_HPP
