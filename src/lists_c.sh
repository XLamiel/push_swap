
for archivo in /home/xl/gitroot/push_swap2/src/*.c; do
	if [ -f "$archivo" ]; then
		echo "========================================"
		echo "ARCHIVO: $archivo"
		echo "========================================"
		cat "$archivo"
		echo -e "\n"
	fi
done
