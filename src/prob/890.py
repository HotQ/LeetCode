class Solution(object):
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        res = list()
        for word in words:
            dct1 = dict()
            dct2 = dict()
            matched = True
            for i in range(len(pattern)):
                if pattern[i] not in dct1:
                    dct1[pattern[i]] = word[i]
                else:
                    if(dct1[pattern[i]] != word[i]):
                        matched = False
                        break
                if word[i] not in dct2:
                    dct2[word[i]] = pattern[i]
                else:
                    if(dct2[word[i]] != pattern[i]):
                        matched = False
                        break
            if matched:
                res.append(word)
        return res
