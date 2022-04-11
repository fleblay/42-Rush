#!/bin/bash

RET=""
FAIL="0"
TOTAL="0"

function test_aff_param ()
{
	(( TOTAL++ ))
	echo ${FUNCNAME[0]} "$@"
	./yasl_aff_param "$@"  2>.error
	RET=$(cat .error)
	test -z "$RET" && echo -e "\x1b[32mOK\x1b[0m" || (echo -e "\x1b[31mKO\x1b[0m" && echo -e "output :\x1b[33m" ./yasl_aff_param "$@" "\x1b[0m")
	test ! -z "$RET" && echo "output : "  && cat .error && (( FAIL++ ))
}

function test_do ()
{
	(( TOTAL++ ))
	echo ${FUNCNAME[0]} "$@"
	./yasl_do "$@"  2>.error
	RET=$(cat .error)
	test -z "$RET" && echo -e "\x1b[32mOK\x1b[0m" || (echo -e "\x1b[31mKO\x1b[0m" && echo -e "output :\x1b[33m" ./yasl_do "$@" "\x1b[0m")
	test ! -z "$RET" && echo "output : "  && cat .error && (( FAIL++ ))
}

function test_repeat ()
{
	(( TOTAL++ ))
	echo ${FUNCNAME[0]} "$@"
	./yasl_repeat "$@"  2>.error
	RET=$(cat .error)
	test -z "$RET" && echo -e "\x1b[32mOK\x1b[0m" || (echo -e "\x1b[31mKO\x1b[0m" && echo -e "output :\x1b[33m" ./yasl_repeat "$@" "\x1b[0m")
	test ! -z "$RET" && echo "output : "  && cat .error && (( FAIL++ ))
}

function test_fact ()
{
	(( TOTAL++ ))
	echo ${FUNCNAME[0]} "$@"
	./yasl_fact "$@"  2>.error
	RET=$(cat .error)
	test -z "$RET" && echo -e "\x1b[32mOK\x1b[0m" || (echo -e "\x1b[31mKO\x1b[0m" && echo -e "output :\x1b[33m" ./yasl_fact "$@" "\x1b[0m")
	test ! -z "$RET" && echo "output : "  && cat .error && (( FAIL++ ))
}

function test_split ()
{
	(( TOTAL++ ))
	echo ${FUNCNAME[0]} "$@"
	./yasl_split "$@"  2>.error
	RET=$(cat .error)
	test -z "$RET" && echo -e "\x1b[32mOK\x1b[0m" || (echo -e "\x1b[31mKO\x1b[0m" && echo -e "output :\x1b[33m" ./yasl_split "$@" "\x1b[0m")
	test ! -z "$RET" && echo "output : "  && cat .error && (( FAIL++ ))
}

function test_base64 ()
{
	(( TOTAL++ ))
	echo ${FUNCNAME[0]} "$@"
	echo -n "$1" | ./display_b64  2>.error
	RET=$(cat .error)
	test -z "$RET" && echo -e "\x1b[32mOK\x1b[0m" || (echo -e "\x1b[31mKO\x1b[0m" && echo -e "output :\x1b[33m" ./display_b64 "$@" "\x1b[0m")
	test ! -z "$RET" && echo "output : "  && cat .error && (( FAIL++ ))
}

test_aff_param
test_aff_param ''
test_aff_param '' ''
test_aff_param 'simple' 'test'
test_aff_param 'simple' 'test'

test_do
test_do ''
test_do '' ''
test_do '' '' ''
test_do '2' 
test_do '2' '1'
test_do '2' '+' '1'
test_do '2' '-' '1'
test_do '2' '*' '1'
test_do '2' '/' '1'
test_do '2' '%' '1'
test_do '2' '<' '1'
test_do '2' '>' '1'
test_do '2' '>=' '1'
test_do '2' '<=' '1'
test_do '2' '==' '1'
test_do '2' '!=' '1'

test_repeat
test_repeat '3'
test_repeat '3' 'fred'
test_repeat '3' 'fred' 'fredo'
test_repeat '0' 'fred' 'fredo'
test_repeat '+0' 'fred' 'fredo'
test_repeat '-0' 'fred' 'fredo'
test_repeat '+3' 'fred' 'fredo'
test_repeat '+3+' 'fred' 'fredo'

test_fact
test_fact '2'
test_fact '2' 'toto'
test_fact '-2'
test_fact '+2'
test_fact 'toto'
test_fact '0'
test_fact '-0'
test_fact '+0'
test_fact '1toto'
test_fact '1toto2'
test_fact 'a1toto2'
test_fact '2.0'
test_fact '1.999'
test_fact '-1.999'
test_fact '0.0'
test_fact '5'
test_fact '10'
test_fact '20'
test_fact '21'
test_fact '22'

test_split
test_split ''
test_split 'fred'
test_split '+' 'fred'
test_split 'fred' 'fred'
test_split '' ''
test_split '' 'fred'
test_split 'fred' ''
test_split 'a' 'afraeda'
test_split 'a' 'aafredaaa'
test_split 'a' 'aafred'
test_split 'a' 'afred'
test_split 'a' 'freda'
test_split 'a' 'fredaa'
test_split 'a' 'afreda'
test_split 'a' 'aaaaa'

test_base64 ''
test_base64 'a'
test_base64 'aa'
test_base64 'aaa'
test_base64 'aaaaa'
test_base64 '////'

echo "FAILURE :" $FAIL "/" $TOTAL
rm .error
