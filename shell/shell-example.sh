#!/bin/bash
#!/bin/bash -x
# ********************************************************
# @file: shell-example.sh
# @author: ZhuBinQiang <zhu.binqiang@163.com>
# @create time: 2021-04-06 11:17:37
# @last modified: 2021-04-06 14:52:46
# @description:
# ********************************************************

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

comment() {
    # one line comment

    ## multiline comment
<<"COMMIT"
this is comment line 1
this is comment line 2
this is comment line 3
COMMIT

    COMMENT_BLOCK=
    if [ ${COMMENT_BLOCK} ]; then
        echo "comment1"
        echo "comment2"
        echo "comment3"
    fi

}

calc() {
    local a=1
    local b=3

    local c1=$((a+b))
    echo "${a} + ${b} = ${c1}"

    let c2=a+b
    echo "${a} + ${b} = ${c2}"

    let "c3 = a + b"
    echo "${a} + ${b} = ${c3}"

    local c4=$(expr ${a} + ${b})
    echo "${a} + ${b} = ${c4}"

    local c5=$((a+1))
    echo "${a} + 1 = ${c5}"

    ## bc
    local c6=$(echo "${a}+${b}" | bc)
    echo "${a} + ${b} = ${c6}"

    local c7=$(echo "scale=2; ${a} / ${b}" | bc)
    echo "${a} / ${b} = ${c7}"

    local sqrt2=$(echo "scale=3; sqrt(2)" | bc)
    echo "square root of 2 = ${sqrt2}"

    ## -l: math library
    local pi=$(echo "scale=10; 4*a(1)" | bc -l)
    echo ${pi}

    ## printf
    printf '%d\t%d\t%d\n' 0xA 0xB 0xC
}

if_else() {
    local i=1
    if [ "${i}" -gt "0" ]; then
        echo "${i} is a positive number"
    elif [ "${i}" -lt "0" ]; then
        echo "${i} is a negative number"
    else
        echo "${i} is zero"
    fi

    if test -e /etc/passwd; then
        echo "it exists"
    else
        echo "it doesn't exist"
    fi

    [ -e /etc/passwd ] && echo "alright it exists" || echo "it doesn't exist"

    ## () this is subprocess
    if ( type git &> /dev/null ); then
        echo "git exists"
    else
        echo "git is not found!"
    fi


    ## refer to https://www.zhihu.com/question/266787434
    ## [: posix shell, the last parameter must be ]
    ## [[, (()): bash only
    local os="ubuntu"
    if [ ${os} == "ubuntu" -o ${os} == "debian" ]; then
        echo "this is debian/ubuntu: [ -o ]"
    fi

    if [ ${os} == "ubuntu" ] || [ ${os} == "debian" ] ; then
        echo "this is debian/ubuntu: [] || []"
    fi

    if [[ ${os} == "ubuntu" || ${os} == "debian" ]] ; then
        echo "this is debian/ubuntu: [[ || ]]"
    fi

    if [[ ${os} == "ubuntu" ]] || [[ ${os} == "debian" ]] ; then
        echo "this is debian/ubuntu: [[ ]] || [[ ]]"
    fi

    if ( echo ${os} | grep -iq "ub" ) || \
        ( echo ${os} | grep -iq "de" ); then
        echo "this is debian/ubuntu: () || ()"
    fi

    ## regular expression
    ## refer to https://man.linuxde.net/docs/shell_regex.html
    local num=56789
    ### there can't be "" or '' on right side
    if [[ ${num} =~ ^[0-9]+$ ]]; then
        echo "${num} is a number"
    fi
}

case_statement() {
    local word="two"
    case ${word} in
        "one" )
            echo "1"
            ;;
        "two" )
            echo "2"
            ;;
        "three" )
            echo "3"
            ;;
        * )
            echo "Usage: $0 {one|two|three}"
            ;;
    esac
}

getopts_case() {
    ## a: cmd -a XXX
    ## hv cmd -h -v
    while getopts "a:hv" opt; do
        case $opt in
            a          )  echo "-a: $OPTARG"   ;;
            h|help     )  echo "Usage"; exit 0   ;;
            v|version  )  echo "$0 -- Version 1.0"; exit 0   ;;

            * )  echo -e "\n  Option does not exist : $OPTARG\n"
                usage; exit 1   ;;
        esac
    done

    echo ${OPTIND}
    shift $(($OPTIND-1))
    echo $0
    echo $*
}

getopt_case() {
    local args=$(getopt -l "iteration:" -o "f:s:t:i:n:v:C:p:h" -- "$@")

    eval set -- "$args"

    while [ $# -ge 1 ]; do
        case "$1" in
            --)
                # No more options left.
                shift
                break
                ;;
            -s)
                local s="$2"
                shift
                ;;
            -i | --iteration)
                local iteration="$2"
                shift
                ;;
            -n)
                local name="$2"
                shift
                ;;
            -h)
                echo "Display some help"
                exit 0
                ;;
        esac

        shift
    done

	echo "name:${name}"
	echo "iteration:${iteration}"
}

for_statement() {
    for i in a b c d; do
        echo ${i}
    done

    for i in {1..5}; do
        echo ${i}
    done

    for i in $(cut -d '=' -f1 /etc/os-release); do
        echo ${i}
    done

    for i in $(seq 1 5); do
        echo ${i}
    done

    local s=0
    for((i=1; i<=100; i++)) {
        s=$((s+i))
    }
    echo "1 + 2 + 3 + ... + 100 = ${s}"
}

while_statement() {
    local i=1
    local s=0
    while [[ "${i}" -le "100" ]]; do
        s=$((s+i))
        # i=$((i+1))
        i=$(expr ${i} + 1)
    done
    echo "1 + 2 + 3 + ... + 100 = ${s}"

    i=1
    while (( ${i} <= 5 )); do
        echo "Count is: ${i}"
        ((i++))
    done
}

util_statement() {
    local i=1
    local s=0
    until [[ "${i}" -gt "100" ]]; do
        s=$((s+i))
        i=$((i+1))
    done
    echo "1 + 2 + 3 + ... + 100 = ${s}"
}

array() {
    local list1=(3 4 5 1 2)
    for i in ${list1[@]}; do
        echo "[${i}]"
    done
    for i in $(seq 0 4); do
        echo "${i}: ${list1[$i]}"
    done

    local list2=(
/proc/buddyinfo
/proc/cpuinfo
/proc/meminfo
/proc/pagetypeinfo
/proc/slabinfo
/proc/vmallocinfo
)

    echo '${!list2[@]}:' "${!list2[@]}"
    echo "xxxxxxxxxxxxxxxxxxxxxxxx"

    local len=${#list2[@]}
    for((i=0; i<${len}; i++)) {
        echo "${i}: ${list2[$i]}"
    }


    local ARGS=()
    # local ARGS
    # ARGS=()
    ARGS+=(-a)
    ARGS+=(-b)
    ARGS+=(-c 123)

    echo "ARGS: ${ARGS[@]}"
}

_print_array() {
    local list=$1
    for i in ${list[*]}; do
        echo "[${i}]"
    done
}

pass_array() {
    local list=(1 2 3 4 5 '6 7' 8)
    echo ${list[*]}

    ## there must be ""
    _print_array "${list[*]}"
}


map() {
    ## refer to https://zhuanlan.zhihu.com/p/289274320
    declare -A dict=(
        [main]="main-branch"
        [master]="master-branch"
        [dev]="dev-branch"
)
    dict["fix"]="fix-branch"

    for key in ${!dict[@]}; do
        echo "${key}: ${dict[$key]}"
    done

    ## all values
    echo -n "All values: "
    for value in ${dict[@]}; do
        echo -n "${value} "
    done
    echo ""
}

fun() {
    echo '$#':"$#"

    echo "\$0:$0"
    echo "\$1:$1"
    echo "\$4:$4"

    echo "\$@:$@"
    for i in "$@"; do
        echo -en "[${i}]  "
    done
    echo -e "\n"

    echo "\$*:$*"
    for i in "$*"; do
        echo -en "[${i}]  "
    done
    echo

    echo "shift ..."
    shift
    echo "shift  \$@:$@"

    shift 3
    echo "shift 3\$@:$@"
}

fun_show() {
    fun 1 2 3 '4 5' 6 7 8
}

background_wait() {
    sleep 5 &
    local pid=$!
    echo "sleeping ..."
    wait ${pid}
    echo "wake up"
}

string() {
    local s="12345"
    echo "s: ${s}"

    echo "length: ${#s}"
    echo '${s:1:3}': "${s:1:3}"


    local f="abc.tar.gz"
    echo "f: ${f}"

    ## Remove matching prefix pattern
    echo '${f#*.}': "${f#*.}"
    echo '${f##*.}': "${f##*.}"

    ## Remove matching suffix pattern
    echo '${f%.*}': "${f%.*}"
    echo '${f%%.*}': "${f%%.*}"


    ## substitute
    local t="1:2:3:4:5"
    echo "t: ${t}"

    echo '${t/:/;}': "${t/:/;}"
    echo '${t//:/;}': "${t//:/;}"

    ## prefix
    echo '${t/#1:2:/_}': "${t/#1:2:/_}"

    ## suffix
    echo '${t/%4:5/_}': "${t/%4:5/_}"

    local s1="ONE,TWO,THREE,FOUR,FIVE"
    echo 's1': "${s1}"
    local array_s1=(${s1//,/ })
    echo '(${s1//,/ })': "${array_s1[@]}"

    ## True if the length of string is zero
    [[ -z ${s} ]]

    ## True if the length of string is non-zero
    [[ -n ${s} ]]

    ## set default string
    : ${E:=456}
    echo "E: ${E}"

    ## set default string
    ## ${s:-"xxx"}
    local A=123
    echo "A: ${A}"
    echo '${A:-"AAAAA"}': ${A:-"AAAAA"}
    local B=
    echo "B: ${B}"
    echo '${B:-"BBBBB"}': ${B:-"BBBBB"}

    ## ${s:+"xxx"}
    local C=123
    echo "C: ${C}"
    echo '${C:+"CCCCC"}': ${C:+"CCCCC"}
    local D=
    echo "D: ${D}"
    echo '${D:+"DDDDD"}': ${D:+"DDDDD"}

    ## mulit-string
    echo "<HTML>
    <HEAD>
          <TITLE>Page Title</TITLE>
    </HEAD>
    <BODY>
          Page body.
    </BODY>
</HTML>"

    local files=$(
cat << EOF
/proc/buddyinfo
/proc/cpuinfo
/proc/meminfo
/proc/pagetypeinfo
/proc/slabinfo
/proc/vmallocinfo
EOF
)
    ## one line
    echo ${files}
    ## new line
    echo "${files}"

    local tmp=$(mktemp)
    cat << EOF > ${tmp}
11111111111111111
22222222222222222
33333333333333333
EOF
    echo ${tmp}
}

read_file() {
    local f=/etc/passwd

    while read line; do
        echo "[${line}]"
    done < ${f}

    cat ${f} | while read line; do
        echo "[${line}]"
    done

}

run_with_root_or_sudo() {
    (( EUID != 0 )) && exec sudo -E -- "$0" "$@"
}

run_sudo() {
    PASS='password'
    echo ${PASS} | sudo -S fdisk -l

    ## invalidates the user's cached credentials
    sudo -k

    sudo LD_LIBRARY_PATH=.:/usr/local/lib64 ffmpeg

    sudo -u user mkdir /datadis
}


read_line() {
    read -p "Name: " name

	stty -echo
	read -p "Password: " pass

    ## echo input characters
	stty echo

    echo -e "\nName: " ${name}
    echo "Password: ${pass}"
}

log2file() {

    ## refer to https://unix.stackexchange.com/questions/42728/what-does-31-12-23-do-in-a-script
    cat << EOF
#!/bin/bash -exu
exec 3>&1 4>&2

trap 'exec 2>&4 1>&3' 0 1 2 3
exec 1> script.log 2>&1

pwd

ls 12345

date
EOF

}

## refer to https://blog.csdn.net/MyySophia/article/details/128966914
handle_parallel() {
    SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
    RESULTS=${SCRIPT_DIR}/log
    test="1,2,3"
    # echo -n "${test}" | parallel --lb -d, "rm -rf $RESULTS/log_{#}/ ; mkdir -p $RESULTS/log_{#}/"
    echo -n "$test" | parallel --group -d, "echo thread_{#}; ZE_AFFINITY_MASK={}; mkdir -p ${RESULTS}/{}.log"

    return 0

    seq 5 | parallel seq {} '>' example.{}
    # for i in $(seq 5); do echo $(seq $i) > example-for.$i;done

    ## ::: 后面跟的是其从命令行的输入
    parallel echo ::: 1 2 3 4 5

    parallel echo counting lines';' wc -l ::: example.*

    ## dry-run
    parallel --dry-run echo count {1} {2} ';' wc {1} {2} ::: -c -l ::: example.*
}


handle_backgroud_process() {
    ## the backgroud jobs will continue to run after the script has been terminated.
    (
        for((i=0; i<=15; i++)); do
            echo ${i}
            sleep 1
        done
    )& pid=$!

    echo pid: ${pid}
    wait ${pid}
}

# read_line
# string
# read_file
# comment
# array
# pass_array
# map
# run_with_root_or_sudo
# calc
# if_else
# case_statement
# getopts_case -a XXX -h -v
# getopt_case -n name --iteration XXX
# for_statement
while_statement
# util_statement

# fun_show
# fun
# background_wait

# log2file

# handle_parallel

# handle_backgroud_process



