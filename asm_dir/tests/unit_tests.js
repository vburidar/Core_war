const {exec} = require('child_process');

path = require("path");
exec(`cp ${__dirname}/../../champs/*.s ${__dirname}/mine; cp ${__dirname}/../../champs/*.s ${__dirname}/vm_champs; rm ${__dirname}/vm_champs/*.cor;rm ${__dirname}/mine/*.cor;rm temp_test;make re -C ${__dirname}/..`, () => {
	var P = 0;
	var F = 0;
	var arr = (fs = require('fs'))
	.readdirSync(__dirname + '/mine');
	arr.forEach((filename, i) => {
		var a = path.resolve(`${__dirname}/mine/${filename}`).slice(0, -2);
		var b = path.resolve(`${__dirname}/vm_champs/${filename}`).slice(0, -2);
		exec(`${__dirname}/../asm_cure ${a}.s`, (err, stdout, stderr) => {
			exec(`${__dirname}/rasm ${b}.s`, (berr, bstdout, bstderr) => {
				var ar = stdout + stderr;
				var br = bstdout + bstderr;
				if (ar.match("Writing output") && br.match("Writing output"))
				{
						exec(`diff ${a}.cor ${b}.cor`, (err, stdout, stderr) => {
							if (!(stdout.length))
								pass(filename, "Both files were created and are identical.", "");
							else {
								exec(`hexdump ${a}.cor > temp_hex_mine; hexdump ${b}.cor > temp_hex_vm_champs; diff temp_hex_mine temp_hex_vm_champs`, (err, stdout, stderr) => {
									fail(filename, "Different files", (err + stderr + stdout).slice(0, 2048));
								});
							}
						});
				}
				else if (!(ar.match("Writing output")) && !(br.match("Writing output")) && !(ar.match(/fault|bus|free/i)))
					pass(filename, "Both ASMs returned an error", "Mine:", ar, "vm_champs:", br);
				else if (ar.match(/fault|bus|free/i))
					fail(filename, "My ASM probably crashed", ar);
				else if (!(ar.match("Writing output")) && (br.match("Writing output")))
				{
					exec(`${__dirname}/rcorewar ${b}.cor`, (err, stdout, stderr) => {
						if ((stderr + stdout).match(/error/i))
							pass(filename, "Corewar and my ASM both returned an error.", stdout + stderr);
						else if (!(a.includes('inv')))
							fail(filename, "My ASM returned an error when compiling a valid file.", ar + stdout + stderr);
						else
							pass(filename, "My ASM return an error that isn't detected by the vm_champs ASM(this is not necessarily a mistake.)", bstdout + bstderr);
					});
				}
				else
					fail(filename, "My corewar compiled an invalid .s file.", bstdout + bstderr);
			});
		});
	});
	var show_msg = (title, text) => {
		console.log('_________________________');
		console.log(title);
		console.log(text);
	}
	var fail = (filename, title, text) =>
	{
		show_msg(title, text);
		console.log(`\x1b[31mFAILING ${F++ +1}/${arr.length} tests\x1b[0m`, filename);
		if (P + F == arr.length)
			exec('rm ${__dirname}/*/*.cor;rm temp_hex_mine; rm temp_hex_vm_champs', () => {});
	}
	var pass = (filename, title, text) =>
	{
		show_msg(title, text);
		console.log(`\x1b[32mPASSING ${P++ +1}/${arr.length} tests\x1b[0m`, filename);
		if (P + F == arr.length)
			exec('rm ${__dirname}/*/*.cor;rm temp_hex_mine; rm temp_hex_vm_champs', () => {});
	}
});
