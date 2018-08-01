var async = require("async"); var fs = require("fs"); var c = fs.readdirSync("../asm/mine").filter(x => x.includes('.cor')); const {exec} = require('child_process');
var F = 0;
var P = 0;
var show_msg = (arr) => {
	console.log('_____________________________________________________________________________________________________________________________');
	arr.forEach(x => console.log(x));
}
var fail = (arr, filename, id) =>
{
	la[filename] = 1;
	show_msg(arr);
	console.log(`Test nº ${id}:	\x1b[31mFAILING ${F++ +1}/${t.length} tests\x1b[0m`, filename);
};
var pass = (arr, filename, id) =>
{
	la[filename] = 1;
	show_msg(arr);
	console.log(`Test nº ${id}:	\x1b[32mPASSING ${P++ +1}/${t.length} tests\x1b[0m`, filename);
};
var la = {};
var test = (f, zaz, vburidar, stderr, callback) => {
//	var zaz = fs.readFileSync(`zaz/${files[0]}_${files[1]}`).toString();
	var z = 0;
	//var vburidar = stdout.split('\n');
	var msg_arr = [`./corewar ../asm/mine/${f}`];
	if (!zaz.length)
		msg_arr.push("Zaz vm probably returned an error");
	else
	{
		var first_diff = -1;
		var n_diff = 0;
		var difo = {}
		for (var i = 0; i < zaz.length && i < vburidar.length; i++)
		{
			if (zaz[i] != vburidar[i])
			{
				zaz[i] = `\x1b[31m${zaz[i]}\x1b[0m`;
				vburidar[i] = `\x1b[31m${vburidar[i]}\x1b[0m`;
			}
		}
		for (var i = 0; i < zaz.length && i < vburidar.length; i++)
		{
			if (zaz[i] != vburidar[i])
			{
				n_diff++;
				if (first_diff == -1)
				{
					msg_arr.push(`First diff at line ${i}:`);
					msg_arr.push(`Zaz:`);
					msg_arr.push('_______________________________');
					msg_arr = msg_arr.concat(zaz.slice(i - 2, i + 3));
					msg_arr.push('_______________________________');
					msg_arr.push(`Us:`);
					msg_arr.push('_______________________________');
					msg_arr = msg_arr.concat(vburidar.slice(i - 2, i + 3));
					msg_arr.push('_______________________________');
					first_diff = i;
				}
			}
		}
		if (n_diff)
			msg_arr.push(`${n_diff} different lines(before any potential crash)`);
		if (zaz.length < vburidar.length)
			msg_arr.push(`${vburidar.length - zaz.length} extraneous lines`);
	}
	if (stderr.length)
	{
		fs.writeFileSync(`errors/${f}.zaz.error`, stderr);
		msg_arr.push(`\x1b[31mAn error was detected and stored in errors/${f}.zaz.error\x1b[0m`);
	}
	else if (vburidar.length < zaz.length)
		msg_arr.push(`${zaz.length - vburidar.length} missing lines`);
	if(t.filter(x => !(la[x])).length < 10)
		console.log(t.filter(x => !(la[x])));
	if ((n_diff && !z) || stderr.length)
		fail(msg_arr, f, t.indexOf(f));
	else
		pass(msg_arr, f, t.indexOf(f));
	callback();
};
var t = [];
t = require("./v.json");//.slice(0, 1)
//t = ["Kappa.cor"];
/*t = [ 'meowluigi.cor',
  //'lld.cor',
  'big_feet.cor',
//  'gateau.cor',
 // 'Kappa.cor',
  'helltrain.cor',
  //'salamahenagalabadoun.cor',
//  'perso.cor'
 ]*/
if (!isNaN(process.argv[2] * 1) && !isNaN(process.argv[3] * 1))
	t = t.slice(process.argv[2] * 1, process.argv[3] * 1);
var i = 0; path = require("path");
exec(`make`, (err, stdout, stderr) => {
	console.log("ok")
	if (stderr && stderr.length && stderr.match(/error|warning/i))
	{
		console.log(stderr);
		if (!(stderr.match("creating archive")))
			return (0);
	}
	console.log("okay");
	async.eachLimit(t, 4, function(f, callback) {
		try{
		console.log("r", f)
	exec(/*`${c.filter(x => !(fs.existsSync('../asm/mine/' +x))).map(x => `../asm/asm ../asm/mine/${x.replace('.cor', '.s')}`).join(';')};*/` ../asm/rcorewar -v 31 ../asm/mine/${f}`, {maxBuffer: 512 * 1024 * 1024},
		(err, zazout, stderr) => {
			console.log(f);
			exec(`./corewar -v ../asm/mine/${f}`, {maxBuffer: 512 * 1024 * 1024},
			(err2, vbout, stderr2) => {
				test(f, zazout.split("\n"), vbout.split("\n"), stderr2 || "" , callback);
			});
		});
		}
		catch(err)
		{
			console.log("STDOUT WAS PROBABLY TOO LONG", err);
			callback();
		}
	}, function(err) {
		console.log("end");
	});
});
