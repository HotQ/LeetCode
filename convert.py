# coding=utf-8

SOT = 3
sour = open("SOURCE.md", 'r')
dest = open("README.md", 'w')
bg1 = {'Easy':   ' bgcolor="#33cc33"',
       'Medium': ' bgcolor="#f0ad4e"',
       'Hard':   ' bgcolor="#d9534f"'}
LOL = list()
SOH = dict()


'''
Parse
'''


count = 1
total = 976
solved = 0
while 1:
    line = sour.readline()
    if line[0] == '|':
        count += 1
        if count == SOT:
            break
    else:
        dest.writelines(line)

while True:
    line = sour.readline()
    if not line.startswith('|'):
        break
    line = map(lambda words: words.strip(),
               line.rstrip('\n').strip('|').split('|'))
    LOL.append(line)
    if line[0] != '':
        solved += 1

for line in sour.readlines():
    if not line.startswith('['):
        continue
    line = line.rstrip('\n').lstrip('[').replace(' ', '').split(']:')
    SOH[line[0]] = line[1]

dest.write("<progress value=%d max=%d></progress> <strong>%d</strong> / %d = %.2f %% " % (solved, total, solved, total, 100 * float(solved) / total))

'''
Generate
'''


def writetd(context, fp, attr=''):
    fp.write('\t\t<td%s>%s</td>\n' % (attr, context))


def dealhref(context):
    if context.startswith('!'):
        context, herf = context.split('][')
        res = '<img src = "%s">%s</a>' % (SOH[herf.rstrip(']')], context.lstrip('!['))
        return res
    if context.startswith('['):
        context, herf = context.split('][')
        res = '<a href = "%s">%s</a>' % (SOH[herf.rstrip(']')], context.lstrip('['))
        return res
    return context


def getrgb(r1, r2, r3, pos):
    if pos == 1:
        return r3

    def hs2int(rgb):
        rgb = '0x' + rgb.lstrip('#')
        dec = int(rgb, 16)
        return dec / 65536, dec / 256 % 256, dec % 256
    r1 = hs2int(r1)
    r2 = hs2int(r2)
    res = 0
    for i in range(3):
        res = res*256 + (int(r1[i]*(1 - pos) + r2[i] * pos))
    return str(hex(res)).lstrip('0x')


dest.write('''
<table>
\t<tr>
\t\t<th><div align="right">#</div></th>
\t\t<th><div align="left">Title</div></th>
\t\t<th>Difficulty</th>
\t\t<th>Languge</th>
\t\t<th><div align="right">Runtime</div></th>
\t\t<th>Time Complexity</th>
\t\t<th>Tag</th>
\t</tr>
''')

_diff = LOL[0][2]
for line in LOL:
    if line[2] != '':
        _diff = line[2]

    dest.write('\t<tr>\n')
    writetd('<div align="right">%s</div>' % line[0], dest)
    writetd(dealhref(line[1]), dest)
    writetd('<font color=#ffffff>%s' % (line[2]), dest, bg1[_diff])
    writetd(dealhref(line[3]), dest)
    bgc = ' bgcolor="#%s"' % (getrgb('#ee332e', '#1bbc1b', '#33cc33', float(line[4].rstrip('%'))/100))
    writetd('<div align="right"><strong><font color=#ffffff>%s</strong></div>' % (line[4]), dest, bgc)
    writetd(dealhref(line[5]), dest)
    writetd(dealhref(line[6]), dest)
    dest.write('\t</tr>\n')

dest.write('</table>\n\n## License\nThis project is licensed under <a href = "./LICENSE">GLWTPL<a>\n')

sour.close()
dest.close()
