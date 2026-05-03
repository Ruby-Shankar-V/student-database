CC        = gcc
CFLAGS    = -Wall -Wextra
TARGET    = dbase
INSTALL   = /sbin

OBJS = main.o \
       add_new_record.o \
       show_the_list.o \
       save.o \
       delete_record_name.o \
       delete_record_rollno.o \
       delete_all.o \
       count.o \
       reverse_list.o \
       read_data_file.o \
       print_slow.o \
       search_rollno.o \
       search_name.o \
       search_percentage.o \
       name_sorting.o \
       rollno_sorting.o \
       percentage_sorting.o \
	   db_utils.o

# ─────────────────────────────────────────────
#  Default: build the binary
# ─────────────────────────────────────────────
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
	@echo ""
	@echo "  Build successful → ./$(TARGET)"
	@echo "  Run  'sudo make install'  to install to $(INSTALL)/$(TARGET)"
	@echo ""

# ─────────────────────────────────────────────
#  Object file rules
# ─────────────────────────────────────────────
main.o: main.c header.h
	$(CC) $(CFLAGS) -c main.c

add_new_record.o: add_new_record.c header.h
	$(CC) $(CFLAGS) -c add_new_record.c

show_the_list.o: show_the_list.c header.h
	$(CC) $(CFLAGS) -c show_the_list.c

save.o: save.c header.h
	$(CC) $(CFLAGS) -c save.c

delete_record_name.o: delete_record_name.c header.h
	$(CC) $(CFLAGS) -c delete_record_name.c

delete_record_rollno.o: delete_record_rollno.c header.h
	$(CC) $(CFLAGS) -c delete_record_rollno.c

delete_all.o: delete_all.c header.h
	$(CC) $(CFLAGS) -c delete_all.c

count.o: count.c header.h
	$(CC) $(CFLAGS) -c count.c

reverse_list.o: reverse_list.c header.h
	$(CC) $(CFLAGS) -c reverse_list.c

read_data_file.o: read_data_file.c header.h
	$(CC) $(CFLAGS) -c read_data_file.c

print_slow.o: print_slow.c header.h
	$(CC) $(CFLAGS) -c print_slow.c

search_rollno.o: search_rollno.c header.h
	$(CC) $(CFLAGS) -c search_rollno.c

search_name.o: search_name.c header.h
	$(CC) $(CFLAGS) -c search_name.c

search_percentage.o: search_percentage.c header.h
	$(CC) $(CFLAGS) -c search_percentage.c

rollno_sorting.o: rollno_sorting.c header.h
	$(CC) $(CFLAGS) -c rollno_sorting.c

name_sorting.o: name_sorting.c header.h
	$(CC) $(CFLAGS) -c name_sorting.c

percentage_sorting.o: percentage_sorting.c header.h
	$(CC) $(CFLAGS) -c percentage_sorting.c

db_utils.o: db_utils.c header.h
	gcc -c db_utils.c

# ─────────────────────────────────────────────
#  Install → /sbin/dbase  (requires sudo)
# ─────────────────────────────────────────────
install: $(TARGET)
	@echo "Installing $(TARGET) to $(INSTALL)/$(TARGET) ..."
	install -o root -g root -m 755 $(TARGET) $(INSTALL)/$(TARGET)
	@echo ""
	@echo "  ✔  $(INSTALL)/$(TARGET) installed successfully!"
	@echo "  Run  'dbase --help'  to get started."
	@echo ""

# ─────────────────────────────────────────────
#  Uninstall  (requires sudo)
# ─────────────────────────────────────────────
uninstall:
	@echo "Removing $(INSTALL)/$(TARGET) ..."
	rm -fv $(INSTALL)/$(TARGET)
	@echo "  ✔  Uninstalled."

# ─────────────────────────────────────────────
#  Clean build artefacts
# ─────────────────────────────────────────────
clean:
	rm -fv $(OBJS) $(TARGET)

.PHONY: all install uninstall clean