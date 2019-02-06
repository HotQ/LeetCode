class Codec:
    def __init__(self):
        self.count = 0
        self.l2s = dict()
        self.s2l = dict()
        
        
    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        if longUrl in self.l2s:
            return 'http://tinyurl.com/' + l2s[longUrl]
        else:
            self.count+=1
            self.l2s[longUrl] = self.count
            self.s2l[self.count] = longUrl
            return 'http://tinyurl.com/' + str(self.count)

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return self.s2l[int(shortUrl.split('/')[-1])]
               

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
