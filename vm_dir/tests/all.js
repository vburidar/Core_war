var p = ["r2", "%123456789", "%4321", "987654321", "4321"];
var op = ["live", "ld", "st", "add", "sub", "and", "or", "xor", "zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork"];
var l = [];
var r = [];


op.forEach(o => {
	for (var i = 0; i < 3; i++)
	{
		p.forEach(x => {
			r = [];
			r[0] = x;
			if (i == 0)
			{
				l.push(`${o} ${r.join(', ')}\n`);
			}
			else {
				p.forEach(x => {
					r[1] = x;
					if (i == 1)
						l.push(`${o} ${r.join(', ')}\n`);
					else {
						p.forEach(x => {
							r[2] = x;
							l.push(`${o} ${r.join(', ')}\n`);
						});
					}
				})
			}
		})
	}
})
var k = [];
const {exec} = require('child_process');
var syn = require('child_process').execSync;

var async = require("async");
var fs = require("fs");
async.eachLimit(l, 4, function(x, callback) {
	var r = Math.random() + new Date().getTime();
	var f = "temp/" + x.replace(/\s+/g, '_') + ".s";
	fs.writeFileSync(f,
		[`.name "${x.slice(0,-1)}"\n`,
		`.comment "${x.slice(0,-1)}"\n`,
	x].join(''));
	exec(`../asm/rasm ${f}`,
	(err, stdout, stderr) => {
		if (stdout.match("Writing output"))
		{
			try {
				syn(`../asm/rcorewar -v 31 ${f.replace('.s', '.cor')} > ${f.replace('.s', '.cor')}.zaz`);
			} catch (e) {
				console.log(k.length)
				k.push(x);
			}
		}
		callback();
	});
}, () => {
	/*fs.writeFileSync("ultimate.s",
	[`.name "crap"\n'`,
	'.comment "crappy"\n'
].concat(k).join(''));
	*/console.log("end")
});
