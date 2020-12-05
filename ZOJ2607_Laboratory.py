
# x1*x3 >= s1
# x1*x4 >= s2
# x2*x3 >= s3
# x2*x4 >= s4
# x3=max{s1/x1,s3/x2}
# x4=max{s2/x1,s4/x2}
# min((x1+x2)*(x3+x4))

# x1*x3=max{s1,s3*x1/x2}
# x1*x4=max{s2,s4*x1/x2}
# x2*x3=max{s1*x2/x1,s3}
# x2*x4=max{s2*x2/x1,s4}
# x2/x1 -> t
# S=s3max{s1/s3,1/t}+s4max{s2/s4,1/t}+s1max{t,s3/s1}+s2max{t,s4/s2}

# t>s4/s2 -> 1/t<s2/s4

# P1=s1+s2+s1*t+s2*t (t>max{s3/s1,s4/s2})
# P2=s1+s4/t+s1*t+s4 (s3/s1<t<s4/s2)
# P3=s3/t+s2+s3+s2*t (s4/s2<t<s3/s1)
# P4=s3/t+s4/t+s3+s4 (t<min{s3/s1,s4/s2})

# P1_min=(s1+s2)*(max{s3/s1,s4/s2}+1) (t=max{s3/s1,s4/s2})
# P4_min=(s3+s4)*(1/min{s3/s1,s4/s2}+1) (t=min{s3/s1,s4/s2})

import sys
def main():
    while 1:
        ss=sys.stdin.readline().strip()
        if len(ss)==0:
            break
        nums=[float(i) for i in ss.split(' ')]
        s1=nums[0]
        s2=nums[1]
        s3=nums[2]
        s4=nums[3]
        S_min=0x3f3f3f3f
        t=1

        if (s1+s2)*(max(s3/s1,s4/s2)+1)<S_min:
            S_min=(s1+s2)*(max(s3/s1,s4/s2)+1)
            t=max(s3/s1,s4/s2)
        if (s3+s4)*(1/min(s3/s1,s4/s2)+1)<S_min:
            S_min=(s3+s4)*(1/min(s3/s1,s4/s2)+1)
            t=min(s3/s1,s4/s2)
        if s3/s1<s4/s2:
            if (s4/s1)**0.5>s3/s1 and (s4/s1)**0.5<s4/s2:
                if s1+s4+2*((s1*s4)**0.5)<S_min:
                    S_min=s1+s4+2*((s1*s4)**0.5)
                    t=(s4/s1)**0.5
            elif (s4/s1)**0.5<=s3/s1:
                if s1+s4+s4*s1/s3+s3<S_min:
                    S_min=s1+s4+s4*s1/s3+s3
                    t=s3/s1
            elif (s4/s1)**0.5>=s4/s2:
                if s1+s4+s2+s1*s4/s2<S_min:
                    S_min=s1+s4+s2+s1*s4/s2
                    t=s4/s2
        elif s3/s1>=s4/s2:
            if (s3/s2)**0.5>s4/s2 and (s3/s2)**0.5<s3/s1:
                if s2+s3+2*((s2*s3)**0.5)<S_min:
                    S_min=s2+s3+2*((s2*s3)**0.5)
                    t=(s3/s2)**0.5
            elif (s3/s2)**0.5<=s4/s2:
                if s2+s3+s2*s3/s4+s4<S_min:
                    S_min=s2+s3+s2*s3/s4+s4
                    t=s4/s2
            elif (s3/s2)**0.5>=s3/s1:
                if s2+s3+s1+s2*s3/s1<S_min:
                    S_min=s2+s3+s1+s2*s3/s1
                    t=s3/s1
        a1=float(1)
        a2=float(t)
        a3=max(s1/a1,s3/a2)
        a4=max(s2/a1,s4/a2)
        print("{:.10}".format(S_min))
        print("{:10} {:10} {:10} {:10}".format(a1,a2,a3,a4))

if __name__=='__main__':
    main()

