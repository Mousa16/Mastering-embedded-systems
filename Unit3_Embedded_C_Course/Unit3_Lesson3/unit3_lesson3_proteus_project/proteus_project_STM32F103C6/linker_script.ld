/* Linker Script for cortex-m3 
Eng. Mahmoud Mousa */

MEMORY
{
	flash(RX) : ORIGIN = 0x08000000, LENGTH = 128K
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}


SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_text = .;
	}> flash

	.data : {
	_S_Data = . ;
		*(.data)
	. = ALIGN(4);
	_E_Data = . ;
	}> sram AT> flash

	.bss : {
	_S_Bss = . ;
		*(.bss*)
	_E_Bss = . ;
	. = ALIGN(4);
	. = . + 0x1000;
	_stack_top = .;
	}> sram
}