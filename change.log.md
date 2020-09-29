# Changelog

## src/configure.ac

```
Line95:
AC_SUBST(CXXFLAGS, "-std=c++98 -O3")
To
AC_SUBST(CXXFLAGS, "-std=c++11 -O3")
```

## src/Util/ClusterReader.cpp

```
Line 70:
     bool good = getline(*m_pReader, line);
To
     bool good = static_cast<bool>(getline(*m_pReader, line));
```

## src/SGA/rmdup.cpp

```
Line 235:
        bool valid = getline(*reader_vec[currReaderIdx], line);
To
        bool valid = static_cast<bool>(getline(*reader_vec[currReaderIdx], line));
```

## src/Util/StdAlnTools.cpp

```
Line 122:
        bool success = parser >> code;
To
        bool success = static_cast<bool>(parser >> code);
```

## src/bin/sga-align

```
Line 1:
#! /usr/bin/env python
To
#!/usr/bin/env python3

Line 17:
    print cmd
To
    print (cmd)

Line 32:
        print 'Error: the two reads files are the same'
To
        print ('Error: the two reads files are the same')

Line68-72
    print 'usage: sga-align [options] <contigs file> <input files>'
    print 'align reads to contigs'
    print 'Options:'
    print '       --name=STR          Use STR as the basename for the output files.'
    print '       -t,--threads=N      Use N threads when running bwa.'
To
    print ('usage: sga-align [options] <contigs file> <input files>')
    print ('align reads to contigs')
    print ('Options:')
    print ('       --name=STR          Use STR as the basename for the output files.')
    print ('       -t,--threads=N      Use N threads when running bwa.')

Line 82-83:
except getopt.GetoptError, err:
        print str(err)
To
except getopt.GetoptError:
        print (str(err))

Line 96
            print 'Unrecognized argument', oflag
To
            print ('Unrecognized argument' + oflag)

Line 101
    print 'Error, a contigs file and reads file must be provided'
To
    print ('Error, a contigs file and reads file must be provided')

Line 110:
    print 'Error, at least one input file must be specified'
To
    print ('Error, at least one input file must be specified')

Line13-114:
print contigFile
print readFiles
To
print (contigFile)
print (readFiles)
```

## src/bin/sga-asqg2dot.pl

```
Line 1:
#! /usr/bin/perl
To
#!/usr/bin/env perl
```

## src/bin/sga-astat.py

```
Line 1:
#! /usr/bin/env python
To
#!/usr/bin/env python3

Line 33-41
    print 'usage: sga-astat.py in.bam'
    print 'Compute Myers\' a-statistic for a set of contigs using the read alignments in in.bam'
    print 'Options:'
    print '    -m=INT          only compute a-stat for contigs at least INT bases in length'
    print '    -b=INT          use the longest INT contigs to perform the initial estimate'
    print '                    of the arrival rate (default: ' + str(numContigsForInitialEstimate) + ')' 
    print '    -n=INT          perform INT bootstrap iterations of the estimate'
    print '    -g=INT          use INT as the genome size instead of estimating it'
    print '    --no-duplicates do not use duplicate reads to calculate statistics'
To
    print ('usage: sga-astat.py in.bam')
    print ('Compute Myers\' a-statistic for a set of contigs using the read alignments in in.bam')
    print ('Options:')
    print ('    -m=INT          only compute a-stat for contigs at least INT bases in length')
    print ('    -b=INT          use the longest INT contigs to perform the initial estimate')
    print ('                    of the arrival rate (default: ' + str(numContigsForInitialEstimate) + ')' )
    print ('    -n=INT          perform INT bootstrap iterations of the estimate')
    print ('    -g=INT          use INT as the genome size instead of estimating it')
    print ('    --no-duplicates do not use duplicate reads to calculate statistics')

Line 45-46:
except getopt.GetoptError, err:
        print str(err)
To
except getopt.GetoptError:
        print (str(err))

Line 66:
    print 'Error: a BAM file must be provided\n'
To
    print ('Error: a BAM file must be provided\n')

Line 177:
        print '%s\t%d\t%d\t%d\t%f\t%f' % (cd.name, cd.len, cd.nlen, cd.n, cd.n / (cd.nlen * arrivalRate), cd.astat)
To
        print ('%s\t%d\t%d\t%d\t%f\t%f' % (cd.name, cd.len, cd.nlen, cd.n, cd.n / (cd.nlen * arrivalRate), cd.astat))
```

## src/bin/sga-bam2de.pl

```
Line 1:
#! /usr/bin/perl
To
#!/usr/bin/env perl
```

## src/bin/sga-beetl-index.pl

```
Line 1:
#! /usr/bin/perl
To
#!/usr/bin/env perl

Line11-12
my $SGA_BIN = "/nfs/users/nfs_j/js18/work/devel/sga/src/build-lenny/SGA/sga";
my $BEETL_BIN = "/nfs/users/nfs_j/js18/work/devel/BEETL/Beetl";
To
my $SGA_BIN = "sga";
my $BEETL_BIN = "Beetl";
```

## src/bin/sga-call-variants.pl

```
Line 1:
#! /usr/bin/perl
To
#!/usr/bin/env perl
```

## src/bin/sga-deinterleave.pl

```
Line 1:
#! /usr/bin/perl
To
#!/usr/bin/env perl
```

## src/bin/sga-diffCalls.pl

```
Line 1:
#! /usr/bin/perl
To
#!/usr/bin/env perl
```

## src/bin/sga-joinedpe

```
Line 1:
#! /usr/bin/env python
To
#!/usr/bin/env python3

Line 12:
        print 'Error: Reads are incorrectly paired ', record1[0], record2[0]
To
        print ('Error: Reads are incorrectly paired ' + record1[0] + " " + record2[0])

Line 33:
        print 'Error: joined record does not have the correct format ', record[0]
To
        print ('Error: joined record does not have the correct format ' + record[0])

Line 79:
        print 'Unknown record header: ', line
To
        print ('Unknown record header: ' + line)

Line 93-101:
    print 'sga-joinedpe [-o outfile] FILE'
    print 'allow rmdup to be performed on entire paired end reads'
    print 'if the --join option is provided, two consequetive records in FILE will be concatenated into one read.'
    print 'if the --split option is provided, each record in FILE will be split into two'
    print '\nOptions: '
    print '          -o, --outfile=FILE    Write results to FILE [default=stdout]'
    print '              --join            Join the reads together'
    print '              --split           Split the reads apart'
    print '              --help            Print this usage message'
To
    print ('sga-joinedpe [-o outfile] FILE')
    print ('allow rmdup to be performed on entire paired end reads')
    print ('if the --join option is provided, two consequetive records in FILE will be concatenated into one read.')
    print ('if the --split option is provided, each record in FILE will be split into two')
    print ('\nOptions: ')
    print ('          -o, --outfile=FILE    Write results to FILE [default=stdout]')
    print ('              --join            Join the reads together')
    print ('              --split           Split the reads apart')
    print ('              --help            Print this usage message')

Line 114:
except getopt.GetoptError, err:
        print str(err)
To
except getopt.GetoptError:
        print (str(err))

Line 130:
            print 'Unrecognized argument', oflag
To
            print ('Unrecognized argument' + oflag)

Line 135:
    print 'Error: Exactly one input file must be provided'
To
    print ('Error: Exactly one input file must be provided')

Line 139:
    print 'Error: One of --join or --split must be provided'
To
    print ('Error: One of --join or --split must be provided')

Line 143:
    print 'Error: Only one of --join or --split can be provided'
To
    print ('Error: Only one of --join or --split can be provided')

Line 161:
            print 'Error, record lengths differ'
To
            print ('Error, record lengths differ')
```

## src/bin/sga-mergeDriver.pl

```
Line 1:
#! /usr/bin/perl
To
#!/usr/bin/env perl
```

## src/bin/sga-popcat.pl

```
Line 1:
#! /usr/bin/perl
To
#!/usr/bin/env perl
```

## src/bin/sga-preqc-report.py

```
Line 1:
#!/usr/bin/env python
To
#!/usr/bin/env python3


```

## src/bin/sga-rename.pl


```
Line 1:
#! /usr/bin/perl
To
#!/usr/bin/env perl
```

## src/bin/sga-vcf-dedup.pl

```
Line 1:
#! /usr/bin/perl
To
#!/usr/bin/env perl
```
