#!/bin/sh

CURRDIR=$(cd "$(dirname "$0")" && pwd)
REPORDIR=$(cd "${CURRDIR}/.." && pwd)
OUTFILE="${CURRDIR}/test.out"
ERRFILE="${CURRDIR}/test.err"
EXECUTABLE="${REPORDIR}/computorv2"

rm -rf "${OUTFILE}"
rm -rf "${ERRFILE}"

for testdir in ${CURRDIR}/tests/*; do
    "${EXECUTABLE}" < "${testdir}/stdin" 1> "${OUTFILE}" 2> "${ERRFILE}"
    if ! diff "${testdir}/stdout" "${OUTFILE}" > /dev/null; then
        echo "FAIL: ${testdir}"
        exit 1
    fi

    if ! diff "${testdir}/stderr" "${ERRFILE}" > /dev/null; then
        echo "FAIL: ${testdir}"
        exit 1
    fi
done
